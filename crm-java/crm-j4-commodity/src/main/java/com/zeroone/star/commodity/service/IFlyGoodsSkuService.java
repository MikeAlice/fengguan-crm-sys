package com.zeroone.star.commodity.service;

import com.zeroone.star.commodity.entity.FlyGoodsSku;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.CommoditySkuDto;
import com.zeroone.star.project.dto.j4.commodity.CommodityEditSkuDto;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.query.j4.commodity.GoodsSkuQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 商品sku规格价格信息表 服务类
 * </p>
 *
 * @author zhenglw
 * @since 2023-10-24
 */
public interface IFlyGoodsSkuService extends IService<FlyGoodsSku> {
    JsonVO<Boolean> modifyCommoditySku(CommodityEditSkuDto commodityEditSkuDto);

    JsonVO<PageDTO<CommoditySkuDto>> queryCommoditySku(GoodsSkuQuery query);

    JsonVO<Boolean> removeCommoditySku(List<Integer> commodityIdList);
}
