package com.zeroone.star.orgstructure.modules.role.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.modules.role.entity.RoleEntity;
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
 * <p>
 * 权限列表 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
public interface RoleService extends IService<RoleEntity> {
    JsonVO<List<RoleTreeVO>> listNameTree(GetRoleTreeNameQuery getRoleTreeNameQuery);

    PageDTO<QueryRoleDTO> listAll(RoleQuery roleQuery);
    /**
     * 获取下拉列表部门名称数据
     *
     * @return 获取结果
     */
    JsonVO<List<GetNameRoleVO>> getnamerole();
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
