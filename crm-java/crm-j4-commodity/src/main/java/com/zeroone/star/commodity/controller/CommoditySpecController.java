package com.zeroone.star.commodity.controller;

//import com.zeroone.star.commodity.service.ICommoditySpecService;
import com.zeroone.star.commodity.service.IFlyGoodsSpecService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.SpecDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j4.commodity.CommoditySpecApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j4.commodity.CommoditySpecQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import springfox.documentation.spring.web.json.Json;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import javax.validation.constraints.Min;

/**
 * <p>
 * 商品规格 前端控制器
 * </p>
 * @author Tezz
 * @since 2023-10-21
 */

@RestController
@RequestMapping("/goods/commoditySpec")
@Api(tags = "基础数据-商品管理-商品规格")
@Validated
public class CommoditySpecController implements CommoditySpecApis {

    @Resource
    IFlyGoodsSpecService iflyGoodsSpecService;

    @PutMapping("modify-spec")
    @ApiOperation(value = "修改商品规格")
    @Override
    public JsonVO<Boolean> modifyData(@Validated SpecDTO specDTO) {
//        return iflyGoodsSpecService.modifyData(specDTO);

        boolean result = iflyGoodsSpecService.modifyData(specDTO);
        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"修改成功");
        } else {
            return JsonVO.create(false,ResultStatus.FAIL.getCode(),"修改失败");
        }

    }

    @DeleteMapping("delete-spec")
    @ApiOperation(value = "删除商品规格")
    @Override
    public JsonVO<Boolean> deleteData(int specId) {
//        return iflyGoodsSpecService.deleteData(specDTO);
        boolean result = iflyGoodsSpecService.deleteData(specId);
        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"删除成功");
        } else {
            return JsonVO.create(false,ResultStatus.FAIL.getCode(),"删除失败");
        }



    }

    @PostMapping("add-spec")
    @ApiOperation(value = "增加商品规格")
    @Override
    public JsonVO<Boolean> addData(@Validated SpecDTO specDTO) {
        //return iflyGoodsSpecService.addData(specDTO);
        boolean result = iflyGoodsSpecService.addData(specDTO);
        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"添加成功");
        } else {
            return JsonVO.create(false,ResultStatus.FAIL.getCode(),"添加失败");
        }
    }

    @GetMapping("get-commodity-spec")
    @ApiOperation(value = "获取商品规格列表(分页+条件)")
    @Override
    public JsonVO<PageDTO<SpecDTO>> getCommoditySpec(@Validated CommoditySpecQuery query) {
        return JsonVO.success(iflyGoodsSpecService.queryAll(query));

    }



}