package com.zeroone.star.orgstructure.modules.role.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.common.utils.ConvertUtil;
import com.zeroone.star.orgstructure.feign.OAuth2Client;
import com.zeroone.star.orgstructure.modules.role.entity.MenuEntity;
import com.zeroone.star.orgstructure.modules.role.entity.MethodEntity;
import com.zeroone.star.orgstructure.modules.role.entity.RoleMenuEntity;
import com.zeroone.star.orgstructure.modules.role.entity.RoleMethodEntity;
import com.zeroone.star.orgstructure.modules.role.mapper.RoleMenuMapper;
import com.zeroone.star.orgstructure.modules.role.service.MenuService;
import com.zeroone.star.orgstructure.modules.role.service.MethodService;
import com.zeroone.star.orgstructure.modules.role.service.RoleMenuService;
import com.zeroone.star.orgstructure.modules.role.service.RoleMethodService;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetMenuRoleMethodTreeVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.CollectionUtils;

import javax.annotation.Resource;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * <p>
 * 角色菜单关联表 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Service
public class RoleMenuServiceImpl extends ServiceImpl<RoleMenuMapper, RoleMenuEntity> implements RoleMenuService {


    @Autowired
    private MenuService menuService;
    @Autowired
    private MethodService methodService;
    @Autowired
    private RoleMethodService roleMethodService;
    @Resource
    private OAuth2Client oAuth2Client;


    /**
     * 获取角色菜单权限树形数据
     * @param roleId
     * @return
     */
    @Override
    public List<GetMenuRoleMethodTreeVO> getRoleCheckPower(Integer roleId) {
        //获取角色关联菜单项id集合
        Set<Integer> menuIdList = getRoleValueList(roleId);
        //获取角色管理的系统方法项id集合
        Set<Integer> roleMethodList = getRoleMethodList(roleId);
        //获取所有菜单项，按sort排序
        List<MenuEntity> menuList = menuService.lambdaQuery().orderByAsc(MenuEntity::getSort).list();
        //获取所有菜单项排序
        List<MethodEntity> methodList = methodService.lambdaQuery().orderByAsc(MethodEntity::getSort).list();
        //过滤一级菜单数据，递归映射集合
        return menuList.stream().filter(item->item.getParentID()==0)
                .map(menu->recursiveFillMenuTreeVo(menu,menuIdList,roleMethodList,menuList,methodList,1))
                .collect(Collectors.toList());
    }
    private GetMenuRoleMethodTreeVO recursiveFillMenuTreeVo(MenuEntity menu, Set<Integer> menuIdSet,
                                        Set<Integer> methodIdSet, List<MenuEntity> menuList,
                                        List<MethodEntity> methodList, int level){

        //递归查询改菜单下的子节点列表
        List<GetMenuRoleMethodTreeVO> nodes = menuList.stream().filter(item -> Objects.equals(item.getParentID(), menu.getId()))
                .map(childMenu -> recursiveFillMenuTreeVo(childMenu, menuIdSet, methodIdSet, menuList, methodList, level + 1))
                .collect(Collectors.toList());
        return handleMenuItemVoValue(menu,menuIdSet,methodIdSet,methodList,level,nodes);
    }

    /**
     *处理当前菜单项
     * @param menu
     * @param menuIdSet
     * @param methodIdSet
     * @param methodList
     * @param level
     * @param nodes
     * @return
     */
    private GetMenuRoleMethodTreeVO handleMenuItemVoValue(MenuEntity menu, Set<Integer> menuIdSet, Set<Integer> methodIdSet, List<MethodEntity> methodList, int level, List<GetMenuRoleMethodTreeVO> nodes) {
        GetMenuRoleMethodTreeVO menuVO = ConvertUtil.sourceToTarget(menu, GetMenuRoleMethodTreeVO.class);
        menuVO.setLevel(level);
        menuVO.setSelectState(menuIdSet.contains(menuVO.getId()) ? 1 : 0);
        boolean isLastLevel = CollectionUtils.isEmpty(nodes);
        menuVO.setType(isLastLevel ? 1 : 0);
        menuVO.setNodes(nodes);
        if (isLastLevel){
            List<GetMenuRoleMethodTreeVO.SysMethodVo> methodVoList = methodList.stream().filter(item -> item.getMenuID().equals(menu.getId()))
                    .map(method -> {
                        GetMenuRoleMethodTreeVO.SysMethodVo methodVo = ConvertUtil.sourceToTarget(method, GetMenuRoleMethodTreeVO.SysMethodVo.class);
                        menuVO.setSelectState(methodIdSet.contains(methodVo.getId()) ? 1 : 0);
                        return methodVo;
                    }).collect(Collectors.toList());
            menuVO.setSysMethodVoList(methodVoList);
        }

        return menuVO;
    }


    /**
     * 获取role_menu表中当前roleId选中的数据
     * @param roleId
     * @return
     */
    private Set<Integer> getRoleValueList(Integer roleId) {
        Set<Integer> list = new HashSet<>();
        QueryWrapper<RoleMenuEntity> wrapper = new QueryWrapper<>();
        wrapper.eq("role_id",roleId);
        List<RoleMenuEntity> roleValueList = baseMapper.selectList(wrapper);
        for (RoleMenuEntity roleMenuEntity : roleValueList) {
            list.add(roleMenuEntity.getMenuId());
        }
        return list;
    }

    /**
     * 获取role_method表中当前roleId选中的数据集合
     * @param roleId
     * @return
     */
    private Set<Integer> getRoleMethodList(Integer roleId) {
        Set<Integer> list = new HashSet<>();
        QueryWrapper<RoleMethodEntity> wrapper = new QueryWrapper<>();
        wrapper.eq("role_id",roleId);
        List<RoleMethodEntity> roleValueList = roleMethodService.getBaseMapper().selectList(wrapper);
        for (RoleMethodEntity roleMethod : roleValueList) {
            list.add(roleMethod.getMethodId());
        }
        return list;
    }


    /**
     * 修改角色菜单权限
     * @param roleId
     * @param menuID
     * @param methodID
     */
    @Override
    @Transactional(rollbackFor = Exception.class)
    public void modifyRoleCheckPowerSave(Integer roleId, List<Integer> menuID, List<Integer> methodID) {
        if (roleId != null) {
            QueryWrapper<RoleMenuEntity> roleMenuEntityQueryWrapper = new QueryWrapper<>();
            roleMenuEntityQueryWrapper.eq("role_id",roleId);
            this.remove(roleMenuEntityQueryWrapper);
            if (!CollectionUtils.isEmpty(menuID)){
                for (Integer menu : menuID) {
                    RoleMenuEntity roleMenuEntity = new RoleMenuEntity();
                    roleMenuEntity.setRoleId(roleId);
                    roleMenuEntity.setMenuId(menu);
                    baseMapper.insert(roleMenuEntity);
                }
            }

            QueryWrapper<RoleMethodEntity> roleMethodQueryWrapper = new QueryWrapper<>();
            roleMethodQueryWrapper.eq("role_id",roleId);
            roleMethodService.remove(roleMethodQueryWrapper);
            if (!CollectionUtils.isEmpty(methodID)){
                for (Integer method : methodID) {
                    RoleMethodEntity roleMethod = new RoleMethodEntity();
                    roleMethod.setRoleId(roleId);
                    roleMethod.setMethodId(method);
                    roleMethodService.getBaseMapper().insert(roleMethod);
                }
            }
        }
        // 远程调用oauth服务，重新加载redis中的方法值-角色集合hash缓存
        oAuth2Client.refreshMethodRoleMap();
    }
}
