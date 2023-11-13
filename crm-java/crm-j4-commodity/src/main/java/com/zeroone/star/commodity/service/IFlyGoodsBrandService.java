package com.zeroone.star.commodity.service;

import com.zeroone.star.commodity.entity.FlyGoodsBrand;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.BrandDTO;
import com.zeroone.star.project.query.j4.commodity.BrandQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 品牌表 服务类
 * </p>
 *
 * @author diwu
 * @since 2023-10-23
 */
public interface IFlyGoodsBrandService extends IService<FlyGoodsBrand> {

    /**
     * 分页查询所有所有数据
     * @return
     */
   PageDTO<BrandDTO>  listAll(BrandQuery query);

    /**
     *
     * @param dto  用于添加品牌的数据传输
     * @return
     */
    boolean addBrand(BrandDTO dto);

    /**
     * 修改品牌的方法
     * @param dto 用于修改品牌的数据传输
     * @return
     */
    boolean updateBrand(BrandDTO dto);


    /**
     * 删除品牌
     * @param commodityBrandId
     * @return
     */
    boolean deleteBrand(int commodityBrandId);
}
