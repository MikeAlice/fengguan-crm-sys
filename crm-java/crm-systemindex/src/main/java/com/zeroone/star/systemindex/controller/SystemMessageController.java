package com.zeroone.star.systemindex.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysMessageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysNoticeDTO;
import com.zeroone.star.project.j1.systemindex.SystemMessageApis;
import com.zeroone.star.project.query.j1.systemindex.FlySysMessageQuery;
import com.zeroone.star.project.query.j1.systemindex.FlySysNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemindex.service.FlySysMessageService;
import com.zeroone.star.systemindex.service.FlySysMessageService1;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService1;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RequestMapping("sysindex/system-message")
@Api(tags = "SystmemMessage")
@RestController
public class SystemMessageController implements SystemMessageApis {

    @Resource
    FlySysMessageService1 flySysMessageService;

    @Resource
    FlySysUserNoticeService1 flySysUserNoticeService;


    @ApiOperation(value = "分页查询系统提示消息")
    @GetMapping("query-all-message")
    @Override
    public JsonVO<PageDTO<FlySysMessageDTO>> queryMessageAll(FlySysMessageQuery flySysMessageQuery) {
        return JsonVO.success(flySysMessageService.listAllMe(flySysMessageQuery));
    }

    @Override
    public JsonVO<FlySysMessageDTO> queryMessageById(int id) {
        return JsonVO.success(flySysMessageService.getByIdMe(id));
    }

    @ApiOperation(value = "编号查询系统提示消息")
    @GetMapping ("query-byid-message")
    public JsonVO<FlySysMessageDTO> queryMessageByIdValidated(int id) {
        return queryMessageById(id);
    }

    @ApiOperation(value = "分页查询系统公告")
    @GetMapping ("query-all-notice")
    @Override
    public JsonVO<PageDTO<FlySysNoticeDTO>> queryNoticeAll(FlySysNoticeQuery flySysNoticeQuery) {
        return JsonVO.success(flySysUserNoticeService.listAllNo(flySysNoticeQuery));
    }

    @Override
    public JsonVO<FlySysNoticeDTO> queryNoticeById(int id) {
        return JsonVO.success(flySysUserNoticeService.getByIdNo(id));
    }

    @ApiOperation(value = "编号查询系统公告")
    @GetMapping ("query-byid-notice")
    public JsonVO<FlySysNoticeDTO> queryNoticeByIdValidated(int id) {
        return queryNoticeById(id);
    }
}
