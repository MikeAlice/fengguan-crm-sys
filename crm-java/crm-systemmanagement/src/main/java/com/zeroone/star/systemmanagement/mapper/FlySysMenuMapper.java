package com.zeroone.star.systemmanagement.mapper;

import com.zeroone.star.systemmanagement.entity.FlySysMenu;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 系统菜单栏目 Mapper 接口
 * </p>
 *
 * @author dzcgood
 * @since 2023-10-20
 */
@Mapper
public interface FlySysMenuMapper extends BaseMapper<FlySysMenu> {

    List<Integer> getChildId(int id);
}
