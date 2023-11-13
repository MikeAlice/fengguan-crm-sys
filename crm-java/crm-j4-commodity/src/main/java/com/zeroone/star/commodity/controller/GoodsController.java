package com.zeroone.star.commodity.controller;


import com.zeroone.star.commodity.service.GoodsService;
import com.zeroone.star.commodity.service.IFlyGoodsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.RecommendDTO;
import com.zeroone.star.project.dto.j4.commodity.ShelfGoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.validation.ContentDTO;
import com.zeroone.star.project.dto.j4.commodity.maintenance.GoodsListDTO;
import com.zeroone.star.project.j4.commodity.GoodsApis;
import com.zeroone.star.project.query.j4.commodity.GoodsQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * @author zhairenhao
 * @date 2023/10/22 22:48
 * @description 商品维护
 */
@RestController
@Api(tags = "基础数据-商品管理-商品维护")
@RequestMapping("/goods/maintenance")
public class GoodsController implements GoodsApis {

    @Autowired
    private GoodsService goodsService;

    @Autowired
    private IFlyGoodsService iFlyGoodsService;

    @PostMapping("list-goods-pages")
    @ApiOperation(value = "分页查询")
    @Override
    public JsonVO<PageDTO<GoodsListDTO>> listGoodsByPages(@RequestBody @Validated GoodsQuery query) {
        return JsonVO.success(iFlyGoodsService.listGoodsByPages(query));
    }

    @PostMapping("update-goods")
    @ApiOperation(value = "修改商品")
    @Override
    public JsonVO<Boolean> updateGoodsById(@RequestBody @Validated GoodsDTO goodsDTO) {
        return JsonVO.success(iFlyGoodsService.updateGoodsById(goodsDTO));
    }


    @GetMapping("get-content/{goodsId}")
    @ApiOperation("获取商品详细信息")
    @Override
    public JsonVO<GoodsDTO> getGoodsDetails(@PathVariable Integer goodsId) {

        return goodsService.getGoodsDetailsById(goodsId);
    }

    @PostMapping("recommend-goods")
    @ApiOperation("推荐/取消推荐(支持批量操作)")
    @Override
    public JsonVO<Boolean> isRecommend(@RequestBody RecommendDTO  recommendDTO) {
        return goodsService.isRecommend(recommendDTO);
    }

    @PostMapping("update-state")
    @ApiOperation("上架/下架商品(支持批量操作)")
    @Override
    public JsonVO<Boolean> goodsState(@RequestBody ShelfGoodsDTO shelfGoodsDTO) {
        goodsService.modifyGoodsState(shelfGoodsDTO);
        return JsonVO.success(true);
    }

    @DeleteMapping("delete-goods")
    @ApiOperation("删除商品(支持批量操作)")
    @Override
    public JsonVO<Boolean> deleteGoods(@RequestBody List<Integer> deleteGoodsIdList) {
        goodsService.removeGoods(deleteGoodsIdList);
        return JsonVO.success(true);
    }

    @GetMapping("get-goodsNames")
    @ApiOperation("获取商品类型名称列表 (用于输入表单下拉列表)")
    @Override
    public JsonVO<List<String>> getGoodsNames() {
        return goodsService.getGoodsNames();
    }

    @PostMapping("add-goods")
    @ApiOperation("发布商品")
    @Override
    public JsonVO<Boolean> addGoods(@RequestBody GoodsDTO goodsDTO) {
        return goodsService.addGoods(goodsDTO);
    }




}