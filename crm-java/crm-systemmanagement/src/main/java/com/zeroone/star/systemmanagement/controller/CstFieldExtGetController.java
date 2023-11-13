package com.zeroone.star.systemmanagement.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtGetDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtplusDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysConfigDTO;
import com.zeroone.star.project.query.j1.systemmanagement.CstFieldExtGetQuery;
import com.zeroone.star.project.query.j1.systemmanagement.FlySysConfigQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.CstFieldExtplusVO;
import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.zeroone.star.systemmanagement.service.CstFieldExtGetService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.zeroone.star.project.j1.systemmanagement.CstFieldExtGetApis;

import javax.annotation.Resource;

@RestController
@Api(tags = "cst-field-ext")
@RequestMapping("/systemmanagement/cst-field-ext")
public class CstFieldExtGetController implements CstFieldExtGetApis{
    @Resource
    CstFieldExtGetService service;


    @Override
    @ApiOperation(value = "获取可扩展表单列表")
    @GetMapping("list")
    public JsonVO<PageDTO<CstFieldExtGetDTO>> listAll(CstFieldExtGetQuery query) {
        return JsonVO.success(service.listAll(query));
    }
}
