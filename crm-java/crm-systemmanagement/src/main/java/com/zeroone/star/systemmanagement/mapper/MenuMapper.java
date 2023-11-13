package com.zeroone.star.systemmanagement.mapper;

import com.zeroone.star.systemmanagement.entity.Menu;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
* @author caesar
* @description 针对表【fly_sys_menu(系统菜单栏目)】的数据库操作Mapper
* @createDate 2023-10-20 19:56:56
* @Entity com.zeroone.star.systemmanagement.entity.Menu
*/
@Mapper
public interface MenuMapper extends BaseMapper<Menu> {

    List<Menu> selectMenuList();

    List<Menu> selectChildrenMenu(Integer parentId);
}




