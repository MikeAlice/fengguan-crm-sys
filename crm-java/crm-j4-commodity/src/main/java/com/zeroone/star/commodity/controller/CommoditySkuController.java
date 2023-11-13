package com.zeroone.star.commodity.controller;

import com.zeroone.star.commodity.service.IFlyGoodsSkuService;
import com.zeroone.star.commodity.service.IStockGoodsSkuService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.CommoditySkuDto;
import com.zeroone.star.project.dto.j4.commodity.CommodityEditSkuDto;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.j4.commodity.CommoditySkuApis;
import com.zeroone.star.project.query.j4.commodity.GoodsSkuQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

/**
 * @program: crm-java
 * @ClassName skuController
 * @description:
 * @author: zlw
 * @create: 2023-10-22 22:04
 * @Version 1.0
 **/

@RestController
@RequestMapping("/goods/commoditySku")
@Api(tags = "基础数据-商品管理-商品SKU")
public class CommoditySkuController implements CommoditySkuApis {


    @Autowired
    private IFlyGoodsSkuService flyGoodsSkuService;

    @ApiOperation(value = "修改SKU")
    @PostMapping("/edit-sku")
    @Override
    public JsonVO<Boolean> modifyCommoditySku(@RequestBody @Validated CommodityEditSkuDto commodityEditSkuDto) {

        return flyGoodsSkuService.modifyCommoditySku(commodityEditSkuDto);
    }


    @ApiOperation(value = "获取SKU列表(分页+条件)")
    @PostMapping("/query-sku")
    @Override
    public JsonVO<PageDTO<CommoditySkuDto>> queryCommoditySku(@RequestBody  GoodsSkuQuery query) {
        return flyGoodsSkuService.queryCommoditySku(query);
    }

    @Override
    @ApiOperation(value = "删除sku")
    @PostMapping("/del-sku")
    public JsonVO<Boolean> removeCommoditySku(@RequestBody List<Integer> commodityIdList ) {
        return flyGoodsSkuService.removeCommoditySku(commodityIdList);
    }
}
