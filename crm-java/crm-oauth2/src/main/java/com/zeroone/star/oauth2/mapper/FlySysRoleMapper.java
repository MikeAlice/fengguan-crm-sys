package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.FlySysRole;
import com.zeroone.star.oauth2.mp.MethodRoleMP;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * @author SleepyHead
 * @description 针对表【fly_sys_role(权限列表)】的数据库操作Mapper
 * @createDate 2023-10-20 20:20:18
 * @Entity generator.domain.FlySysRole
 */
@Mapper
public interface FlySysRoleMapper extends BaseMapper<FlySysRole> {
    /**
     * 通过用户编号查询角色
     * @param userId 用户编号
     * @return 角色列表
     */
    List<FlySysRole> selectByUserId(int userId);

    /**
     * 通过菜单路径获取对应的角色
     * @param path 菜单路径
     * @return 角色列表
     */
    List<FlySysRole> selectByMenuPath(String path);

    List<MethodRoleMP> getMethodRoleList();
}
