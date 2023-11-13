package com.zeroone.star.orgstructure.modules.dept.controller;


import com.zeroone.star.orgstructure.modules.dept.service.DeptService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.AddDeptDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.DeptDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.QueryDeptDTO;
import com.zeroone.star.project.j2.orgstructure.dept.DeptApis;
import com.zeroone.star.project.query.j2.orgstructure.dept.DeptQuery;
import com.zeroone.star.project.query.j2.orgstructure.dept.GetDeptNameTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.dept.DeptTreeVO;
import com.zeroone.star.project.vo.j2.orgstructure.dept.GetNameDeptV0;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 部门表 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@RestController
@RequestMapping("/dept/dept")
@Api(tags = "部门接口")
public class DeptController implements DeptApis {
    @Autowired
    private DeptService deptService;

    @GetMapping("query-all")
    @ApiOperation("获取部门列表 (分页+条件)")
    @Override
    public JsonVO<PageDTO<QueryDeptDTO>> queryAll(@Validated DeptQuery deptQuery) {
        return JsonVO.success(deptService.listAll(deptQuery));
    }

    @GetMapping("list-name-all")
    @ApiOperation(value = "获取部门名称列表数据 (用于输入表单下拉列表)")
    @Override
    public JsonVO<List<GetNameDeptV0>> listNameAll(@ApiParam(value = "部门名称") @RequestParam(required = false) String deptName) {
        return deptService.getnamedept(deptName);
    }

    @PostMapping("add-dept")
    @ApiOperation(value = "新增部门")
    @Override
    public JsonVO<Long> addDept(@RequestBody AddDeptDTO dto) {
        return deptService.addDept(dto);
    }

    @PutMapping("modify-dept")
    @ApiOperation(value = "修改部门")
    @Override
    public JsonVO<Long> modifyDept(@RequestBody DeptDTO dto) {
        return deptService.updateDept(dto);
    }

    @DeleteMapping("remove-dept")
    @ApiOperation(value = "删除部门")
    @Override
    public JsonVO<Long> removeDept(@ApiParam(value = "部门id",required = true) @RequestParam Integer id) {
        return deptService.deleteDept(id);
    }

    @GetMapping("list-name-tree")
    @ApiOperation(value = "获取部门名称结构树")
    @Override
    public JsonVO<List<DeptTreeVO>> listNameTree(GetDeptNameTreeQuery getDeptNameTreeQuery){
        return deptService.getNameTree(getDeptNameTreeQuery);
    }

}

