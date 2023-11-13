package com.zeroone.star.ownerindex.controller;


import com.zeroone.star.ownerindex.entity.Notice;
import com.zeroone.star.ownerindex.service.NoticeService;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.*;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.ownerindex.NoticeRemindApis;
import com.zeroone.star.project.query.j3.ownerindex.SearchNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.ownerindex.GetNoticeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

/**
 * @Description: 公告通知控制类
 * @Author: your name
 * @Date: 2023/10/21 16:26
 */
@RestController
@RequestMapping("/j3-notice-remind")
@Api(tags = "个人首页-公告通知")
public class NoticeRemindController implements NoticeRemindApis {

    @Autowired
    private NoticeService noticeService;

//TODO:公告详情
    @ApiOperation(value = "查看指定公告详情")
    @GetMapping("get-notice")
    @Override
    public JsonVO<GetNoticeVO> getNotice(@RequestParam(value="id",required=true) Integer id){
        GetNoticeVO noticeVO = noticeService.getNoticeById(id);
        return JsonVO.success(noticeVO);
    }

    //TODO:shanchu
    @ApiOperation(value = "删除公告（可批量删除）",notes = "将所选公告的Id封装成list传来,只删一条也是一样操作，多选删除和删除共用接口")
    @PostMapping("remove-notice")
    @Override
    public JsonVO<Boolean> removeNotice(@RequestBody ArrayDTO dto){
        noticeService.deleteById(dto);
        return JsonVO.success(true);
    }

    @ApiOperation(value = "标记已读公告（可批量标记）",notes = "将所选公告的Id封装成list传来,只标记一条也是一样操作，多选标记和标记共用接口")
    @PostMapping("update-notice")
    @Override
    public JsonVO<Boolean> updateNotice(@RequestBody ArrayDTO dto) {
        return JsonVO.success(noticeService.updateNotice(dto));
    }


    @Override
    @ApiOperation("发布公告")
    @PostMapping("add-notice")
    public JsonVO<Boolean> addNotice(AddNoticeDTO dto) throws Exception {
        /*
        三种情况：
            1.发布给部门
            2.发布给个人
            3.发布给部门和特定的个人
         */
        int judge = noticeService.addNotice(dto);
        if (judge >= 1){
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);

    }



    @ApiOperation(value = "获取系统公告")
    @GetMapping("query-notion")
    @Override
    public JsonVO<PageDTO<QueryNoticeDTO>> QueryNoticePage(@Validated SearchNoticeQuery searchNoticeQuery) throws Exception {
        PageDTO<QueryNoticeDTO> queryNoticeDTOPageDTO = noticeService.listNotice(searchNoticeQuery);
        return JsonVO.success(queryNoticeDTOPageDTO);
    }






}
