package com.zeroone.star.systemindex.controller;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;
import com.zeroone.star.project.dto.j1.systemindex.noticeRemindDTO;
import com.zeroone.star.project.j1.systemindex.SystemMessageRemindApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemindex.entity.FlySysMessage;
import com.zeroone.star.systemindex.entity.FlySysUserNotice;
import com.zeroone.star.systemindex.mapper.FlySysMessageMapper;
import com.zeroone.star.systemindex.service.FlySysMessageService;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;
@RestController
@RequestMapping("sysindex")
@Api(tags = "消息、公告通知提醒")
public class SystemMessageRemindController implements SystemMessageRemindApis {

    @Resource
    FlySysMessageService flySysMessageService;
    @Resource
    FlySysUserNoticeService flySysUserNoticeService;
    @Resource
    UserHolder userHolder;
    @ApiOperation(value = "查询消息通知提醒列表")
    @GetMapping ("query-message-notices")
    @Override
    public JsonVO<List<messageRemindDTO>> queryMessageNotices() throws Exception {
        //1.获取登录用户id
        UserDTO user = userHolder.getCurrentUser();
        Integer userId = user.getId();
        //Integer userId = 1;测试数据
        //2.查询fly_sys_message表当前用户信息列表
        List<messageRemindDTO> dtoList = flySysMessageService.listByOwnerUserId(userId);
        //3.将查询结果封装为JsonVO，返回
        return JsonVO.success(dtoList);
    }

    @ApiOperation(value = "查询公告通知提醒列表")
    @GetMapping ("query-announcement-notices")
    @Override
    public JsonVO<List<noticeRemindDTO>> queryAnnouncementNotices() throws Exception {
        //1.获取登录用户id
        UserDTO user = userHolder.getCurrentUser();
        Integer userId = user.getId();
        //2.查询fly_sys_user_notice表当前用户信息列表
        List<noticeRemindDTO> dtoList = flySysUserNoticeService.listByOwnerUserId(userId);
        //3.将查询结果封装为JsonVO，返回
        return JsonVO.success(dtoList);
    }
    @ApiOperation(value = "标记通知为已读")
    @PutMapping ("mark-as-read")
    @Override
    public JsonVO<String> markAsRead(
            @ApiParam("通知类型，0为消息通知提醒，1为公告通知提醒") @RequestParam int messageType,
            @ApiParam("消息id") @RequestParam int id) {
        if (messageType!=0&&messageType!=1){
            return JsonVO.fail("消息类型不正确");
        }
        boolean isSuccess;
        //消息通知
        if (messageType==0){
            //查询消息
            FlySysMessage message = flySysMessageService.lambdaQuery()
                    .eq(FlySysMessage::getId, id)
                    .one();
            //修改状态
            if (message==null){
                return JsonVO.fail("消息不存在");
            }
            message.setFlag(1);
            //更新
            isSuccess = flySysMessageService.updateById(message);
        }else {//公告通知
            FlySysUserNotice announce = flySysUserNoticeService.lambdaQuery()
                    .eq(FlySysUserNotice::getId, id)
                    .one();
            if (announce==null){
                return JsonVO.fail("公告不存在");
            }
            announce.setStatus(1);
            isSuccess = flySysUserNoticeService.updateById(announce);
        }
        if (isSuccess) {
            return JsonVO.success("消息已读");
        }else {
            return JsonVO.fail("消息已读失败");
        }
    }
}
