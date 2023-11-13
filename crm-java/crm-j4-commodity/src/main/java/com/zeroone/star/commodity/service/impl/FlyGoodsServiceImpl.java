package com.zeroone.star.commodity.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.commodity.entity.FlyGoods;
import com.zeroone.star.commodity.entity.FlyGoodsList;
import com.zeroone.star.commodity.mapper.FlyGoodsMapper;
import com.zeroone.star.commodity.service.IFlyGoodsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.maintenance.GoodsListDTO;
import com.zeroone.star.project.query.j4.commodity.GoodsQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class FlyGoodsServiceImpl extends ServiceImpl<FlyGoodsMapper, FlyGoods> implements IFlyGoodsService {

    @Autowired
    private FlyGoodsMapper goodsMapper;

    /**
     * @author zhairenhao
     * @description 获取商品列表（分页+条件）
     * @param query
     * @return PageDTO<GoodsListDTO>
     */
    @Override
    public PageDTO<GoodsListDTO> listGoodsByPages(GoodsQuery query) {
        // 构建分页查询对象
        Page<FlyGoodsList> goodsPage = new Page<>(query.getPageIndex(), query.getPageSize());

        List<FlyGoodsList> goodsList = goodsMapper.getByCondition(query);

        Page<FlyGoodsList> result = goodsPage.setRecords(goodsList);

        return PageDTO.create(result, src -> goodsToGoodsDto(src));
    }

    /**
     * @author zhairenhao
     * @description 修改商品
     * @param goodsDTO
     * @return Boolean
     */
    @Override
    public Boolean updateGoodsById(GoodsDTO goodsDTO) {
        FlyGoods flyGoods = new FlyGoods();
        BeanUtil.copyProperties(goodsDTO,flyGoods);
        int result = goodsMapper.updateById(flyGoods);
        if (result > 0) {
            return true;
        }
        return false;
    }

    /**
     * @param flyGoods
     * @return GoodsListDTO
     * @author zhairenhao
     * @description 映射
     */
    private GoodsListDTO goodsToGoodsDto(FlyGoodsList flyGoods) {
        if (flyGoods == null) {
            return null;
        }

        GoodsListDTO goodsListDTO = new GoodsListDTO();
        goodsListDTO.setGoodsId(flyGoods.getGoodsId());
        goodsListDTO.setPrice(flyGoods.getPrice());
        goodsListDTO.setSales(flyGoods.getSales());
        goodsListDTO.setPicture(flyGoods.getFlyGoodsImg().getImgPath());
        goodsListDTO.setTotalStock(flyGoods.getStockGoodsSkuList().stream().mapToInt(f -> f.getStock()).sum());
        goodsListDTO.setCode(flyGoods.getCode());
        goodsListDTO.setSort(flyGoods.getSort());

        return goodsListDTO;
    }
}
