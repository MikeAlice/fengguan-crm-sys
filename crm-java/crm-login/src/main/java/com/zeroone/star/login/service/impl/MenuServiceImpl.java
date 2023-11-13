package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.FlySysMenu;
import com.zeroone.star.login.mapper.FlySysMenuMapper;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.j1.login.MenuTreeVO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：定义一个Menu数据到MenuTreeNode的属性映射配器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
class MenuTreeNodMapper implements TreeNodeMapper<FlySysMenu> {
    @Override
    public TreeNode objectMapper(FlySysMenu flySysMenu) {
        MenuTreeVO treeNode = new MenuTreeVO();
        // 首先设置TreeNode计算层数使用属性
        treeNode.setTnId(flySysMenu.getId());
        if (flySysMenu.getParentid() == null) {
            treeNode.setTnPid(null);
        } else {
            treeNode.setTnPid(flySysMenu.getParentid());
        }
        // 设置扩展属性
        treeNode.setId(flySysMenu.getId());
        treeNode.setIcon(flySysMenu.getIcon());
        treeNode.setText(flySysMenu.getName());
        treeNode.setHref(flySysMenu.getUrl());
        treeNode.setPid(flySysMenu.getParentid());
        return treeNode;
    }
}

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<FlySysMenuMapper, FlySysMenu> implements IMenuService {

    @Override
    public List<MenuTreeVO> listMenuByRoleName(List<String> roleNames) {
        //1 定义一个存储数据库查询菜单数据的容器
        List<FlySysMenu> menus = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<FlySysMenu> tMenus = baseMapper.selectByRoleName(roleName);
            if (tMenus != null && !tMenus.isEmpty()) {
                menus.addAll(tMenus);
            }
        });
        //3 转换树形结构并返回
        return TreeUtils.listToTree(menus, new MenuTreeNodMapper());
    }
}
