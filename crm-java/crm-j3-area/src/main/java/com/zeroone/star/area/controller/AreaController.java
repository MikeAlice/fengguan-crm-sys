package com.zeroone.star.area.controller;

import com.zeroone.star.area.service.AreaService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.area.*;
import com.zeroone.star.project.j3.area.AreaApis;
import com.zeroone.star.project.query.KeyWordQuery;
import com.zeroone.star.project.query.j3.area.ObtainAreaListQuery;
import com.zeroone.star.project.query.j3.area.ObtainAreaTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.area.AreaListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * 描述：地区管理相关接口实现
 */
@RestController
@RequestMapping("/j3-area")
@Api(tags = "基础数据-地区管理")
public class AreaController implements AreaApis {

    @Autowired
    private AreaService areaService;

    @ApiOperation("获取区域名称结构树")
    @GetMapping ("query-tree")
    @Override
    public JsonVO<List<AreaTreeInfoDTO>> queryTree(ObtainAreaTreeQuery query) {
        return JsonVO.success(areaService.queryTree(query));
    }

    @ApiOperation("获取区域列表")
    @GetMapping ("query-list-area")
    @Override
    public JsonVO<PageDTO<AreaInfoDTO>> listArea(@Validated ObtainAreaListQuery query) {
        return JsonVO.success(areaService.listArea(query));
    }

    @ApiOperation("新增地区")
    @PostMapping("insertArea")
    @Override
    public JsonVO<Boolean> insertArea(InsertAreaDTO dto) {
        return areaService.insertArea(dto);
    }

    @ApiOperation("删除地区")
    @DeleteMapping("deleteArea")
    @Override
    public JsonVO<Boolean> deleteArea(DeleteAreaDTO dto) {
        return areaService.deleteArea(dto);
    }

    @ApiOperation("修改地区")
    @PostMapping("modifyArea")
    @Override
    public JsonVO<Boolean> modifyArea(ModifyAreaDTO dto) {
        return areaService.modifyArea(dto);
    }

    @ApiOperation("获取区域下拉列表")
    @GetMapping("/select-area")
    @Override
    public JsonVO<List<AreaListVO>> getAreaList(KeyWordQuery keyWordQuery) {
        List<AreaListVO> areaList = areaService.getAreaList(keyWordQuery.getKeyWord());
        return JsonVO.success(areaList);
    }
}
