package com.zeroone.star.commodity.mapper;

import com.zeroone.star.commodity.entity.FlyGoods;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.commodity.entity.FlyGoodsList;
import com.zeroone.star.project.query.j4.commodity.GoodsQuery;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 商品表 Mapper 接口
 * </p>
 *
 * @author zhairenhao
 * @since 2023-10-24
 */
@Mapper
public interface FlyGoodsMapper extends BaseMapper<FlyGoods> {
    /**
     * @author zhairenhao
     * @description 多表联合查询
     * @param query
     * @return List<FlyGoods>
     */
    List<FlyGoodsList> getByCondition(GoodsQuery query);

}
