package com.zeroone.star.orgstructure.modules.position.controller;


import com.zeroone.star.orgstructure.modules.position.service.PositionService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.AddPositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.DeletePositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.QueryPositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.UpdatePositionDTO;
import com.zeroone.star.project.j2.orgstructure.position.PositionApis;
import com.zeroone.star.project.query.j2.orgstructure.position.GetPositionNameTreeQuery;
import com.zeroone.star.project.query.j2.orgstructure.position.PositionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.position.GetNamePositionV0;
import com.zeroone.star.project.vo.j2.orgstructure.position.PositionTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 * 职位表 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@RestController
@RequestMapping("/position/position")
@Api(tags = "岗位接口")
public class PositionController implements PositionApis {
    @Autowired
    private PositionService positionService;

    @GetMapping("query-all")
    @ApiOperation("获取岗位列表 (分页+条件)")
    @Override
    public JsonVO<PageDTO<QueryPositionDTO>> queryAll(@Validated PositionQuery positionQuery) {
        return JsonVO.success(positionService.listAll(positionQuery));
    }

    @GetMapping("query-name-all")
    @ApiOperation("获取岗位名称列表数据 (用于输入表单下拉列表)")
    @Override
    public JsonVO<List<GetNamePositionV0>> listNameAll(@ApiParam(value = "岗位名称") @RequestParam(required = false) String positionName) {
        return positionService.getnameposition(positionName);
    }
    @GetMapping("list-name-tree")
    @ApiOperation("获取岗位名称结构树")
    @Override
    public JsonVO<List<PositionTreeVO>> listNameTree(GetPositionNameTreeQuery getPositionNameTreeQuery) {
        return positionService.listNameTree(getPositionNameTreeQuery);
    }

    @PostMapping("add-position")
    @ApiOperation(value = "新增岗位")
    @Override
    public JsonVO<Void> addPosition(@Valid @RequestBody AddPositionDTO addPositionDTO) {
        positionService.addPosition(addPositionDTO);
        return JsonVO.success(null);
    }

    @PutMapping("update-position")
    @ApiOperation(value = "修改岗位")
    @Override
    public JsonVO<Void> updatePosition(@Valid @RequestBody UpdatePositionDTO updatePositionDTO) {
        positionService.updatePosition(updatePositionDTO);
        return JsonVO.success(null);
    }

    @DeleteMapping("delete-position")
    @ApiOperation(value = "删除岗位")
    @Override
    public JsonVO<Void> deletePosition(@ApiParam(value = "岗位ID", required = true) @RequestParam Integer positionId) {
        positionService.deletePosition(positionId);
        return JsonVO.success(null);
    }

}

