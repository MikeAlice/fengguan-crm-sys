package com.zeroone.star.project.j2.orgstructure.role;

import com.zeroone.star.project.dto.j2.orgstructure.role.RoleMenuMethodsDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetMenuRoleMethodTreeVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * 角色菜单关联接口API定义
 *
 * @author 汐
 * @since 2023/10/19
 */
public interface RoleMenuApis {

    /**
     * 获取角色菜单权限树形数据
     * @param roleId  角色ID
     * @return
     */
    JsonVO<List<GetMenuRoleMethodTreeVO>> getRoleCheckPower(@PathVariable Integer roleId);

    /**
     * 修改角色菜单权限
     * @param roleMenuMethodsDTO
     * @return
     */
    JsonVO modifyRoleCheckPowerSave(@RequestBody RoleMenuMethodsDTO roleMenuMethodsDTO);


}
