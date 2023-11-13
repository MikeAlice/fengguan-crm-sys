package com.zeroone.star.area.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.area.entity.Area;
import com.zeroone.star.project.vo.j3.area.AreaListVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface AreaMapper extends BaseMapper<Area> {

    @Select("SELECT id,name FROM fly_sys_area")
    List<AreaListVO> getAreaList();

    @Select("SELECT id,name FROM fly_sys_area WHERE name LIKE concat('%',#{keyWord,jdbcType=VARCHAR},'%')")
    List<AreaListVO> getAreaList(@Param("keyWord") String keyWord);

}
