package com.zeroone.star.oauth2.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.FlySysRole;
import com.zeroone.star.oauth2.mp.MethodRoleMP;

import java.util.List;

/**
 * <p>
 * 角色表 服务类
 * </p>
 *
 * @author 阿伟
 */
public interface IRoleService extends IService<FlySysRole> {
    /**
     * 通过用户编号获取角色列表
     * @param userId 用户编号
     * @return 角色列表
     */
    List<FlySysRole> listRoleByUserId(int userId);

    /**
     * 获取指定菜单路径有访问权限的角色
     * @param path 指定菜单路径
     * @return 角色列表
     */
    List<FlySysRole> listRoleByMenuPath(String path);

    List<MethodRoleMP> getMethodRoleList();
}
