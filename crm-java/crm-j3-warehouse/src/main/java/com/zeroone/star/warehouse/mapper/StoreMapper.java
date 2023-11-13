package com.zeroone.star.warehouse.mapper;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.warehouse.StoreDTO;
import com.zeroone.star.project.vo.j3.warehouse.StoreListVO;
import com.zeroone.star.warehouse.entity.Store;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface StoreMapper extends BaseMapper<Store> {

    /**
     * 根据名字去查找
     */
    @Select("select * from stock_store where name = ${name}")
    StoreDTO selectByName(String name);

    @Select("SELECT store_id,name FROM stock_store")
    List<StoreListVO> getStoreSelect();

    @Select("SELECT store_id,name FROM stock_store WHERE name LIKE CONCAT('%', #{keyWord}, '%')")
    List<StoreListVO> getStoreSelect(String keyWord);

}