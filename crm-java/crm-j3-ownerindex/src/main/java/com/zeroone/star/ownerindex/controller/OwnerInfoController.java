package com.zeroone.star.ownerindex.controller;

import com.zeroone.star.ownerindex.service.MessageService;
import com.zeroone.star.ownerindex.service.NoticeService;
import com.zeroone.star.ownerindex.service.UserService;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyOwnerInfoDTO;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyPwdDTO;
import com.zeroone.star.project.j3.ownerindex.OwnerInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @Description: 个人信息操作相关接口操作实现
 * @Author: your name
 * @Date: 2023/10/20 21:34
 */
@RestController
@RequestMapping("/j3-owner-info")
@Api(tags = "个人首页-个人信息操作")
public class OwnerInfoController implements OwnerInfoApis {

    @Autowired
    private UserService userService;


    @ApiOperation(value = "修改密码")
    @PostMapping("modify-password")
    @Override
    public JsonVO<Boolean> modifyPassword(ModifyPwdDTO dto) throws Exception {
        if (dto == null) {
            throw new RuntimeException("请求参数不能为空");
        }
        Boolean b = userService.modifyPassword(dto);
        if (b != true) {
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }

    @ApiOperation(value = "编辑资料")
    @PostMapping("modify-owner-info")
    @Override
    public JsonVO<Boolean> modifyOwnerInfo(ModifyOwnerInfoDTO dto) throws Exception {
        if (dto == null) {
            throw new RuntimeException("请求参数不能为空");
        }
        Boolean b = userService.modifyOwnerInfo(dto);
        if (b != true) {
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }
}
