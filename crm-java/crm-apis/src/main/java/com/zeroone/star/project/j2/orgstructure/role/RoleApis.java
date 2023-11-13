package com.zeroone.star.project.j2.orgstructure.role;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.AddRoleDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.QueryRoleDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.UpdateRoleDTO;
import com.zeroone.star.project.query.j2.orgstructure.role.GetRoleTreeNameQuery;
import com.zeroone.star.project.query.j2.orgstructure.role.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetNameRoleVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.RoleTreeVO;

import java.util.List;

/**
 * 角色接口API定义
 *
 * @author j2
 * @version 1.0.0
 */
public interface RoleApis {
    /**
     * 角色分页查询
     *
     * @param roleQuery 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<QueryRoleDTO>> queryAll(RoleQuery roleQuery);

    /**
     * 下拉列表角色名称
     *
     * @return 查询结果
     */
    JsonVO<List<GetNameRoleVO>> listNameAll();

    public JsonVO<List<RoleTreeVO>> listNameTree(GetRoleTreeNameQuery getRoleTreeNameQuery);

    /**
     * 添加角色
     *
     * @param dto
     * @return
     */
    JsonVO<Long> addRole(AddRoleDTO dto);

    /**
     * 修改角色信息
     *
     * @param dto
     * @return
     */
    JsonVO<Long> updateRole(UpdateRoleDTO dto);

    /**
     * 删除角色信息
     *
     * @param id
     * @return
     */
    JsonVO<Long> removeRole(Integer id);
}
