package com.zeroone.star.project.j4.commodity;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.BrandDTO;
import com.zeroone.star.project.query.j4.commodity.BrandQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 商品品牌操作的相关接口的定义
 */
public interface CommodityBrandApis {
    /**
     *  修改品牌列表
     * @param dto  修改品牌列表的相关数据
     * @return  返回修改结果 成功为 true
     */
    JsonVO<Boolean>  modifyCommodityBrand( BrandDTO dto);


    /**
     * 添加商品的品牌
     * @param dto  添加品牌的相关数据
     * @return   添加品牌的结果 ，成功为true
     */
    JsonVO<Boolean>  addCommodityBrand(BrandDTO dto);


         /**
          * 获取品牌列表（分页条件查询）
          * @return  BrandVO
          */
        JsonVO<PageDTO<BrandDTO>> queryCommodityBrands(BrandQuery query);


    /**
     * 删除品牌列表
     * @param commodityBrandId  根据id删除品牌列表
     * @return  返回 删除品牌的结果 成功为true
     */
     JsonVO<Boolean>  removeCommodityBrand(int commodityBrandId);


}
