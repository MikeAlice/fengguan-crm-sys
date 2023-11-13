package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysConfigDTO;
import com.zeroone.star.project.j1.systemmanagement.FlySysConfigApis;
import com.zeroone.star.project.query.j1.systemmanagement.FlySysConfigQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanagement.service.IFlySysConfigService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 系统配置表 前端控制器
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@RestController
@Api(tags = "fly-sys-config")
@RequestMapping("/systemmanagement/fly-sys-config")
public class FlySysConfigController implements FlySysConfigApis {
    @Resource
    IFlySysConfigService service;

    @Override
    @ApiOperation(value = "获取系统参数")
    @GetMapping("list")
    public JsonVO<PageDTO<FlySysConfigDTO>> listAll( FlySysConfigQuery query) {
        return JsonVO.success(service.listAll(query));
    }

    @Override
    @ApiOperation(value = "更新系统参数")
    @PutMapping("update")
    public JsonVO<String> updateSysParam( @RequestBody List<FlySysConfigDTO> dtos) {
        return JsonVO.success(service.updateSysParam(dtos));
    }
}

