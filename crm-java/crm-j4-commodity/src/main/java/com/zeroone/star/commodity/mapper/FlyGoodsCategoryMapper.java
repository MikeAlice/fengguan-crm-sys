package com.zeroone.star.commodity.mapper;

import com.zeroone.star.commodity.entity.FlyGoodsCategory;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.*;

import java.util.List;

/**
 * <p>
 * 商品分类表 Mapper 接口
 * </p>
 *
 * @author 张二发
 * @since 2023-10-24
 */
@Mapper
public interface FlyGoodsCategoryMapper extends BaseMapper<FlyGoodsCategory> {

    @Insert("insert into fly_goods_category(category_name)values(#{categoryName})")
    @Options(useGeneratedKeys = true,keyProperty = "categoryId",keyColumn = "category_id")
    int insertCategory(FlyGoodsCategory flyGoodsCategory);

    @Select("select * from fly_goods_category where parent_id = #{parentId}")
    List<FlyGoodsCategory> selectByParentId(@Param("parentId") Integer parentId);
}
