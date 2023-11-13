package com.zeroone.star.systemmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.systemmanagement.entity.Role;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface RoleMapper extends BaseMapper<Role> {
    /**
     * 通过角色名获取对应的菜单资源
     * @param roleName 角色名
     * @return 返回菜单列表
     */
    List<Role> selectByRoleName(String roleName);
}