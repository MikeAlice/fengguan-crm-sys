package com.zeroone.star.commodity.controller;

import com.zeroone.star.commodity.entity.FlyGoodsCategory;
import com.zeroone.star.commodity.service.GoodsCategoryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.*;
import com.zeroone.star.project.dto.j4.commodity.validation.UpdateCategory;
import com.zeroone.star.project.j4.commodity.GoodsCategoryApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/**
 * @author 张二发
 */
@RestController
@Api(tags = "基础数据-商品管理-商品分类")
@RequestMapping("/goods/category")
public class GoodsCategoryController implements GoodsCategoryApis {
    @Resource
    private GoodsCategoryService goodsCategoryService;

    @Override
    @ApiOperation(value = "新增商品分类", consumes = "application/json")
    @PostMapping("/add")
    public JsonVO<Boolean> addGoodsCategory(@RequestBody @Valid AddGoodsCategoryDTO goodsCategoryDTO) {
        return goodsCategoryService.saveGoodsCategory(goodsCategoryDTO);
    }

    @Override
    @ApiOperation(value = "删除商品分类")
    @DeleteMapping("/remove/{goodsCategoryId}")
    public JsonVO<Boolean> removeGoodsCategory(@PathVariable("goodsCategoryId") int goodsCategoryId) {
        return goodsCategoryService.removeGoodsCategory(goodsCategoryId);
    }

    @Override
    @ApiOperation(value = "修改商品分类")
    @PutMapping("/modify")
    public JsonVO<Boolean> modifyGoodsCategory(@RequestBody @Validated(UpdateCategory.class) UpdateGoodsCategoryDTO goodsCategoryDTO) {
        return goodsCategoryService.modifyGoodsCategory(goodsCategoryDTO);
    }

    @Override
    @ApiOperation(value = "获取商品分类")
    @GetMapping("/get/{goodsCategoryId}")
    public JsonVO<UpdateGoodsCategoryDTO> queryGoodsCategory(@PathVariable("goodsCategoryId") int goodsCategoryId) {
        UpdateGoodsCategoryDTO goodsCategory = goodsCategoryService.getGoodsCategory(goodsCategoryId);
        if (goodsCategory == null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),"商品分类不存在");
        }
        return JsonVO.success(goodsCategory);
    }

    @Override
    @GetMapping("/list-goods-category-name-tree")
    @ApiOperation(value = "获取商品分类名称树")
    public JsonVO<List<CategoryNameTreeDTO>> queryGoodsCategoryNameTree() {
        return JsonVO.success(goodsCategoryService.listCategoryNameTree());
    }

    @GetMapping("/list-goods-category")
    @ApiOperation(value = "分页获取商品分类")
    public JsonVO<PageDTO<FlyGoodsCategory>> queryGoodsCategoryTree(int pageNum, int pageSize) {
        return JsonVO.success(goodsCategoryService.listGoodsCategory(pageNum, pageSize));
    }
}
