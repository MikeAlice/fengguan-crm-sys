package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.FlySysMenu;
import com.zeroone.star.oauth2.entity.FlySysRole;
import com.zeroone.star.oauth2.mp.MethodRoleMP;
import com.zeroone.star.oauth2.service.IMenuService;
import com.zeroone.star.oauth2.service.IRoleService;
import com.zeroone.star.project.constant.RedisConstant;
import lombok.extern.slf4j.Slf4j;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：路径与角色资源服务器初始化服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Slf4j
@Service
public class ResourceServiceImpl {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;
    @Resource
    private IMenuService menuService;
    @Resource
    private IRoleService roleService;

    @PostConstruct
    public void init() {
        // 定义缓存map
//        Map<String, List<String>> resourceRolesMap = new TreeMap<>();
//        // 1 获取所有菜单
//        List<FlySysMenu> tMenus = menuService.listAllLinkUrl();
//        tMenus.forEach(flySysMenu -> {
//            // 2 获取菜单对应的角色
//            List<FlySysRole> rolesMenu = roleService.listRoleByMenuPath(flySysMenu.getUrl());
//            List<String> roles = new ArrayList<>();
//            rolesMenu.forEach(role -> roles.add(role.getName()));
//            resourceRolesMap.put(flySysMenu.getUrl(), roles);
//        });

        // 获取方法value-角色role集合
        List<MethodRoleMP> methodRoleMPList = roleService.getMethodRoleList();
        // 方法value-角色role列表分组
        Map<String, List<String>> methodRoleListMap = methodRoleMPList.stream().collect(Collectors.groupingBy(MethodRoleMP::getMethodValue, Collectors.mapping(MethodRoleMP::getRoleName, Collectors.toList())));
        // 删除原缓存信息
        redisTemplate.delete(RedisConstant.RESOURCE_ROLES_MAP);

        //将资源缓存到redis
        redisTemplate.opsForHash().putAll(RedisConstant.RESOURCE_ROLES_MAP, methodRoleListMap);

        log.info("成功刷新redis方法-角色映射hash");
    }
}
