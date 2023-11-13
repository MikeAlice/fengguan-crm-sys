package com.zeroone.star.orgstructure.modules.role.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.modules.role.entity.RoleMenuEntity;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetMenuRoleMethodTreeVO;

import java.util.List;

/**
 * <p>
 * 角色菜单关联表 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
public interface RoleMenuService extends IService<RoleMenuEntity> {

    /**
     * 获取角色菜单权限树形数据
     * @param roleId
     * @return
     */
    List<GetMenuRoleMethodTreeVO> getRoleCheckPower(Integer roleId);


    /**
     * 修改角色菜单权限
     * @param
     * @return
     */
    void modifyRoleCheckPowerSave(Integer orderId, List<Integer> menuID, List<Integer> methodID);




}
