package com.zeroone.star.systemmanagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleListVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;
import com.zeroone.star.systemmanagement.entity.Role;
import com.zeroone.star.systemmanagement.mapper.RoleMapper;
import com.zeroone.star.systemmanagement.service.FlySysRoleListService;
import org.springframework.beans.BeanUtils;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class FlySysRoleListServiceImpl extends ServiceImpl<RoleMapper, Role> implements FlySysRoleListService {
    @Override
    public List<RoleListVO> listRoleListByRoleName(List<String> roleNames) {
        List<RoleListVO> roleVos = new ArrayList<>();
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<Role> tRoles = baseMapper.selectByRoleName(roleName);
            if (tRoles != null && !tRoles.isEmpty()) {
                // 将 Role 列表转换为 RoleVo 列表
                List<RoleListVO> tRoleVos = tRoles.stream().map(role -> {
                    RoleListVO roleVo = new RoleListVO();
                    BeanUtils.copyProperties(role, roleVo);
                    roleVo.setId(roleVo.getId());
                    roleVo.setText(role.getName());
                    roleVo.setPid(roleVo.getPid());
                    return roleVo;
                }).collect(Collectors.toList());
                roleVos.addAll(tRoleVos);
            }
        });


        return roleVos;
    }
}
