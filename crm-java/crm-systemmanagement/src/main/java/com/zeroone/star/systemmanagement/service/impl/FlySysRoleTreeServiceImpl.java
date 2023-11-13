package com.zeroone.star.systemmanagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.j1.login.MenuTreeVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;
import com.zeroone.star.systemmanagement.entity.Role;
import com.zeroone.star.systemmanagement.mapper.RoleMapper;
import com.zeroone.star.systemmanagement.service.FlySysRoleTreeService;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：定义一个Role数据到RoleTreeNode的属性映射配器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
class RoleTreeNodMapper implements TreeNodeMapper<Role> {
    @Override
    public TreeNode objectMapper(Role role) {
        MenuTreeVO treeNode = new MenuTreeVO();
        // 首先设置TreeNode计算层数使用属性
        treeNode.setTnId(Integer.valueOf(role.getId().toString()));
        if (role.getParentID() == null) {
            treeNode.setTnPid(null);
        } else {
            treeNode.setTnPid(Integer.valueOf(role.getParentID().toString()));
        }
        // 设置扩展属性
        treeNode.setId(role.getId());
        treeNode.setText(role.getName());
        treeNode.setHref(role.getIntro());
        treeNode.setPid(role.getParentID());
        return treeNode;
    }
}

public class FlySysRoleTreeServiceImpl extends ServiceImpl<RoleMapper, Role> implements FlySysRoleTreeService {

    @Override
    public List<RoleTreeVO> listRoleTreeByRoleName(List<String> roleNames) {
        //1 定义一个存储数据库查询菜单数据的容器
        List<Role> roles = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<Role> tRoles = baseMapper.selectByRoleName(roleName);
            if (tRoles != null && !tRoles.isEmpty()) {
                roles.addAll(tRoles);
            }
        });
        //3 转换树形结构并返回
        return TreeUtils.listToTree(roles, new RoleTreeNodMapper());
    }

}
