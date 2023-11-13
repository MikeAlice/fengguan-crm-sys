package com.zeroone.star.ownerindex.controller;

import com.zeroone.star.ownerindex.entity.Message;
import com.zeroone.star.ownerindex.service.MessageService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.AddMessageDTO;
import com.zeroone.star.project.dto.j3.ownerindex.MessageDTO;
import com.zeroone.star.project.query.j3.ownerindex.SearchMessageQuery;
import com.zeroone.star.project.j3.ownerindex.MessageRemindApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import javax.validation.constraints.Min;
import java.util.List;

/**
 * @Description: 消息通知控制类
 * @Author: your name
 * @Date: 2023/10/21 16:19
 */
@RestController
@RequestMapping("/j3-message-remind")
@Api(tags = "个人首页-消息通知")
public class MessageRemindController implements MessageRemindApis {

    @Autowired
    private MessageService messageService;

    @ApiOperation(value = "标记消息已读（批量操作）")
    @PostMapping("mark-read-message")
    @Override
    public JsonVO<Boolean> markReadMessage(@RequestBody ArrayDTO dto) throws Exception {
        if (dto.getIds().size() == 0) {
            throw new RuntimeException("消息id列表不能为空");
        }
        Boolean b = messageService.markReadMessage(dto);
        if (b == true) {
            return JsonVO.success(true);
        } else {
            return JsonVO.fail(false);
        }
    }

    @ApiOperation(value = "发布消息")
    @PostMapping("publish-message")
    @Override
    public JsonVO<Boolean> addMessage(@Valid AddMessageDTO dto) throws Exception {
        if (dto == null) {
            throw new RuntimeException("消息不能为空");
        }
        Boolean b = messageService.saveMessage(dto);
        if (b == false) {
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }

    @ApiOperation("根据分页条件获取消息列表")
    @GetMapping("/queryMessage")
    @Override
    public JsonVO<PageDTO<MessageDTO>> queryMessageList(SearchMessageQuery dto) {
        //返回消息分页\条件列表
        PageDTO<MessageDTO> pageList =messageService.queryPage(dto);

        return JsonVO.success(pageList);
    }

    @ApiOperation("查看消息详情")
    @GetMapping("/{id}")
    @Override
    public JsonVO<MessageDTO> selectMessageById(@PathVariable Integer id) {
        MessageDTO message = messageService.selectMessageById(id);
        return JsonVO.success(message);
    }

    @ApiOperation("消息删除")
    @DeleteMapping("/deleteMassage")
    @Override
    public JsonVO<Boolean> deleteMessage(@RequestBody ArrayDTO dto) {
        messageService.deleteMessage(dto);
        return JsonVO.success(true);
    }
}
