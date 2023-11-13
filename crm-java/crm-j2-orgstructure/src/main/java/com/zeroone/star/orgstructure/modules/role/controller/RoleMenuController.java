package com.zeroone.star.orgstructure.modules.role.controller;


import com.zeroone.star.orgstructure.modules.role.service.RoleMenuService;
import com.zeroone.star.project.dto.j2.orgstructure.role.RoleMenuMethodsDTO;
import com.zeroone.star.project.j2.orgstructure.role.RoleMenuApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetMenuRoleMethodTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 角色菜单关联表 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@RestController
@RequestMapping("/role/role-menu")
@Api(tags = "角色菜单关联接口")
public class RoleMenuController implements RoleMenuApis {
    @Autowired
    private RoleMenuService roleMenuService;


    @GetMapping("role-check-power")
    @ApiOperation(value = "获取角色菜单权限树形数据")
    public JsonVO<List<GetMenuRoleMethodTreeVO>> getRoleCheckPower(@ApiParam(value = "角色ID", required = true) @RequestParam Integer roleId) {
        List<GetMenuRoleMethodTreeVO> jsonVO = roleMenuService.getRoleCheckPower(roleId);
        return JsonVO.success(jsonVO);
    }


    @PutMapping("role-check-power-save")
    @ApiOperation(value = "修改角色菜单权限")
    public JsonVO modifyRoleCheckPowerSave(@RequestBody RoleMenuMethodsDTO roleMenuMethodsDTO) {
        roleMenuService.modifyRoleCheckPowerSave(roleMenuMethodsDTO.getOrderId(), roleMenuMethodsDTO.getMenuID(),roleMenuMethodsDTO.getMethodID());
        return JsonVO.success(1);
    }


}