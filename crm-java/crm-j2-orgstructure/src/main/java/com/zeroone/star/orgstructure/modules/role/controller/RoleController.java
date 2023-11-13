package com.zeroone.star.orgstructure.modules.role.controller;


import com.zeroone.star.orgstructure.modules.role.service.RoleService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.AddRoleDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.QueryRoleDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.UpdateRoleDTO;
import com.zeroone.star.project.j2.orgstructure.role.RoleApis;
import com.zeroone.star.project.query.j2.orgstructure.role.GetRoleTreeNameQuery;
import com.zeroone.star.project.query.j2.orgstructure.role.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetNameRoleVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.RoleTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 权限列表 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@RestController
@RequestMapping("/role/role")
@Api(tags = "角色接口")
public class RoleController implements RoleApis {
    @Autowired
    private RoleService roleService;

    @GetMapping("query-all")
    @ApiOperation("获取角色列表 (分页+条件)")
    @Override
    public JsonVO<PageDTO<QueryRoleDTO>> queryAll(@Validated RoleQuery roleQuery) {
        return JsonVO.success(roleService.listAll(roleQuery));
    }

    @GetMapping("query-name-all")
    @ApiOperation("获取角色名称列表数据 (用于输入表单下拉列表)")
    @Override
    public JsonVO<List<GetNameRoleVO>> listNameAll() {
        return roleService.getnamerole();
    }

    @GetMapping("list-name-tree")
    @ApiOperation("获取角色名称结构树")
    @Override
    public JsonVO<List<RoleTreeVO>> listNameTree(GetRoleTreeNameQuery getRoleTreeNameQuery) {
        return roleService.listNameTree(getRoleTreeNameQuery);
    }

    @PostMapping("add-role")
    @ApiOperation(value = "新增角色")
    @Override
    public JsonVO<Long> addRole(@RequestBody AddRoleDTO dto) {
        return roleService.addRole(dto);
    }

    @PutMapping("modify-role")
    @ApiOperation(value = "修改角色")
    @Override
    public JsonVO<Long> updateRole(@RequestBody UpdateRoleDTO dto) {
       return roleService.updateRole(dto);
    }

    @DeleteMapping("remove-role")
    @ApiOperation(value = "删除角色")
    @Override
    public JsonVO<Long> removeRole(@ApiParam(value = "角色ID") @RequestParam("id") Integer id) {
        return roleService.removeRole(id);
    }
}

