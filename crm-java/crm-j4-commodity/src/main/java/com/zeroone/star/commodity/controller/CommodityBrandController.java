package com.zeroone.star.commodity.controller;
import com.zeroone.star.commodity.service.IFlyGoodsBrandService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.BrandDTO;
import com.zeroone.star.project.j4.commodity.CommodityBrandApis;
import com.zeroone.star.project.query.j4.commodity.BrandQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

/**
 *  商品品牌管理操作的相关接口实现
 */
@RestController
@RequestMapping("/goods/commodityBrand")
@Api(tags = "基础数据-商品管理-商品品牌")
@Validated
public class CommodityBrandController implements CommodityBrandApis {


    @Resource
    IFlyGoodsBrandService service;


    @ApiOperation(value = "获取品牌列表条件查询")
    @PostMapping("query-brand")
    @Override
    public JsonVO<PageDTO<BrandDTO>> queryCommodityBrands(@Validated @RequestBody BrandQuery query) {
        return JsonVO.success(service.listAll(query));
    }


    @ApiOperation(value = "修改品牌")
    @PutMapping ("modify-brand")
    @Override
    public JsonVO<Boolean> modifyCommodityBrand(@RequestBody BrandDTO dto) {

        boolean result = service.updateBrand(dto);
        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"修改成功");
        } else {
            return JsonVO.create(false,ResultStatus.FAIL.getCode(),"修改失败");
        }
    }



    @ApiOperation(value = "添加品牌")
    @PostMapping("add-brand")
    @Override
    public JsonVO<Boolean> addCommodityBrand(@Validated @RequestBody  BrandDTO dto) {
        boolean result = service.addBrand(dto);
        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"添加成功");
        } else {
            return JsonVO.create(false,ResultStatus.FAIL.getCode(),"添加失败");
        }
    }



    @ApiOperation(value = "删除品牌列表")
    @DeleteMapping("remove-brand")
    @Override
    public JsonVO<Boolean> removeCommodityBrand(int commodityBrandId) {

        boolean result = service.deleteBrand(commodityBrandId);

        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(), "删除成功");
        } else {
            return JsonVO.create(false, ResultStatus.FAIL.getCode(), "删除失败");
        }

    }
}


