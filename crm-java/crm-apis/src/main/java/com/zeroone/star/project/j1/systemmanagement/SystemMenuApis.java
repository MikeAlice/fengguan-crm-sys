package com.zeroone.star.project.j1.systemmanagement;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuTreeVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuVO;

import java.util.List;

public interface SystemMenuApis {

    JsonVO<MenuTreeVO> getMenuTree();

    JsonVO<List<MenuVO>> getMenuList(Integer id);

}
