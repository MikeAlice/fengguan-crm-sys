package com.zeroone.star.commodity.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.commodity.entity.FlyGoods;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.maintenance.GoodsListDTO;
import com.zeroone.star.project.query.j4.commodity.GoodsQuery;

/**
 * <p>
 * 商品表 服务类
 * </p>
 *
 * @author zhairenhao
 * @since 2023-10-24
 */
public interface IFlyGoodsService extends IService<FlyGoods> {

    PageDTO<GoodsListDTO> listGoodsByPages(GoodsQuery query);

    Boolean updateGoodsById(GoodsDTO goodsDTO);
}
