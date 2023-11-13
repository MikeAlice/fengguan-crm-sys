package com.zeroone.star.systemmanagement.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtGetPageDTO;
import com.zeroone.star.project.j1.systemmanagement.CstFieldExtGetPageApis;
import com.zeroone.star.project.query.j1.systemmanagement.CstFieldExtGetPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanagement.service.CstFieldExtGetPageService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@Api(tags = "cst-field-ext")
@RequestMapping("/systemmanagement/cst-field-ext-plus")
public class CstFieldExtGetPageController implements CstFieldExtGetPageApis {
    @Resource
    CstFieldExtGetPageService service;


    @Override
    @ApiOperation(value = "获取可扩展表单列表（分页）")
    @GetMapping("list-page")
    public JsonVO<PageDTO<CstFieldExtGetPageDTO>> listAll(CstFieldExtGetPageQuery query) {
        return JsonVO.success(service.listAll(query));
    }

}
