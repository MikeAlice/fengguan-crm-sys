package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.FlySysMenu;
import com.zeroone.star.project.vo.j1.login.MenuTreeVO;

import java.util.List;

/**
 * <p>
 * 菜单 服务类
 * </p>
 * @author 阿伟
 */
public interface IMenuService extends IService<FlySysMenu> {
    /**
     * 通过角色名称获取，菜单资源
     * @param roleNames 角色名称
     * @return 返回菜单列表
     */
    List<MenuTreeVO> listMenuByRoleName(List<String> roleNames);
}
