package com.zeroone.star.project.j4.commodity;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.CommoditySkuDto;
import com.zeroone.star.project.dto.j4.commodity.CommodityEditSkuDto;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.query.j4.commodity.GoodsSkuQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface CommoditySkuApis {

    /**
     * 修改SKU
     * @param commodityEditSkuDto  商品sku
     * @return  修改列表的结果 ，成功为true
     */
    JsonVO<Boolean> modifyCommoditySku(CommodityEditSkuDto commodityEditSkuDto);



    /**
     * 获取SKU列表（分页+条件）
     * @param query   搜索对象
     * @return   返回BrandQuery 的数据对象列表
     */
    JsonVO<PageDTO<CommoditySkuDto>> queryCommoditySku(GoodsSkuQuery query);


    /**
     * 删除SKU
     * @param commodityIdList  待删除的id集合
     * @return  返回 删除品牌的结果 成功为true
     */
    JsonVO<Boolean>  removeCommoditySku(List<Integer> commodityIdList);
}
