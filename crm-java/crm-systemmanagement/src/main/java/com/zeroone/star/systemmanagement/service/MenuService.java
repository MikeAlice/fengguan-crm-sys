package com.zeroone.star.systemmanagement.service;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuTreeVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuVO;
import com.zeroone.star.systemmanagement.entity.Menu;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
* @author caesar
* @description 针对表【fly_sys_menu(系统菜单栏目)】的数据库操作Service
* @createDate 2023-10-20 19:56:56
*/
public interface MenuService extends IService<Menu> {

    MenuTreeVO getMenuTree();

    List<MenuVO> getMenuList(Integer id);
}
