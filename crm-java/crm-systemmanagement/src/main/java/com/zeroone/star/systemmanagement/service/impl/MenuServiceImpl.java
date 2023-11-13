package com.zeroone.star.systemmanagement.service.impl;

import cn.hutool.core.collection.CollectionUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuTreeVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuVO;
import com.zeroone.star.systemmanagement.entity.Menu;
import com.zeroone.star.systemmanagement.service.MenuService;
import com.zeroone.star.systemmanagement.mapper.MenuMapper;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

@Mapper(componentModel = "spring")
interface MsMenuStruct {
    MenuTreeVO mdoToTreeVO(Menu menu);
    MenuVO mdoToVO(Menu menu);
}

/**
* @author caesar
* @description 针对表【fly_sys_menu(系统菜单栏目)】的数据库操作Service实现
* @createDate 2023-10-20 19:56:56
*/
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu>
    implements MenuService{

    @Resource
    private MsMenuStruct msMenuStruct;

    @Resource
    private MenuMapper menuMapper;

    @Override
    public MenuTreeVO getMenuTree() {
        List<MenuTreeVO> menus = menuMapper.selectMenuList().stream()
                //转换成MenuTreeVO对象
                .map(msMenuStruct::mdoToTreeVO)
                .collect(Collectors.toList());

        MenuTreeVO menuTreeRoot = new MenuTreeVO();

        MenuTreeVO goal = new MenuTreeVO();

        for (MenuTreeVO menu : menus) {
            Integer pid = menu.getParentId();

            if(pid == 0) menuTreeRoot.addChild(menu);

            else {
                goal.setId(pid);
                int index = Collections.binarySearch(menus, goal, Comparator.comparingInt(MenuTreeVO::getId));

                //父级菜单若被设置为不可见（无法从menus中查找到）
                if(index < 0 || index >= menus.size()) {
                    //throw new RuntimeException("非法菜单状态：子菜单可见但父级菜单不可见");
                    continue;
                }

                MenuTreeVO parent = menus.get(index);
                parent.addChild(menu);
            }

        }

        sortChildrenMenu(menuTreeRoot);

        return menuTreeRoot;
    }

    @Override
    public List<MenuVO> getMenuList(Integer id) {
        return menuMapper.selectChildrenMenu(id).stream().map(msMenuStruct::mdoToVO).collect(Collectors.toList());
    }

    void sortChildrenMenu(MenuTreeVO parent) {

        List<MenuTreeVO> children = parent.getChildren();

        if(Objects.isNull(children))
            return;

        children.sort(Comparator.comparingInt(MenuTreeVO::getSort));

        for (MenuTreeVO child : children) {
            sortChildrenMenu(child);
        }
    }

}




