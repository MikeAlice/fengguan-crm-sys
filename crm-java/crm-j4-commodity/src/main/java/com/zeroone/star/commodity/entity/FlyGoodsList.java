package com.zeroone.star.commodity.entity;

import lombok.Data;

import java.util.List;

/**
 * @author zhairenhao
 * @date 2023/10/27 14:40
 * @description
 */
@Data
public class FlyGoodsList extends FlyGoods{

    private FlyGoodsImg flyGoodsImg;

    private List<StockGoodsSku> stockGoodsSkuList;
}
