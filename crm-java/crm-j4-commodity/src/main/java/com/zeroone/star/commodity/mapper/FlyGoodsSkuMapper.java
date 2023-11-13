package com.zeroone.star.commodity.mapper;

import com.zeroone.star.commodity.entity.FlyGoodsSku;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j4.commodity.CommoditySkuDto;
import com.zeroone.star.project.query.j4.commodity.GoodsSkuQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 商品sku规格价格信息表 Mapper 接口
 * </p>
 *
 * @author zhenglw
 * @since 2023-10-24
 */
@Mapper
public interface FlyGoodsSkuMapper extends BaseMapper<FlyGoodsSku> {


    List<CommoditySkuDto> querySku(@Param("query") GoodsSkuQuery query);

    Integer querySkuCount(@Param("query")GoodsSkuQuery query);
}
