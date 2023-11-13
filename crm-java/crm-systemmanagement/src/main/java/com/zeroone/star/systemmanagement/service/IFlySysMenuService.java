package com.zeroone.star.systemmanagement.service;

import com.zeroone.star.systemmanagement.entity.FlySysMenu;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 系统菜单栏目 服务类
 * </p>
 *
 * @author dzcgood
 * @since 2023-10-20
 */
public interface IFlySysMenuService extends IService<FlySysMenu> {
    /**
     * 获取菜单及其所有子菜单的id
     * @param id
     * @return
     */
    List<Integer> getChildId(int id);
}
