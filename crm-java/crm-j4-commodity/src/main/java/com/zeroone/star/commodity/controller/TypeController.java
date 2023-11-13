package com.zeroone.star.commodity.controller;

import com.zeroone.star.commodity.service.GoodsTypeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.AddNewTypeDTO;
import com.zeroone.star.project.dto.j4.commodity.ModifyTypeDTO;
import com.zeroone.star.project.j4.commodity.GoodTypeInfoApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j4.commodity.GoodsTypeIdQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.commodity.DetailedTypeVO;
import com.zeroone.star.project.vo.j4.commodity.SimpleTypeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;

/**
 * @author Ak5ma1
 *
 */
@Api(tags = "基础数据-商品管理-商品类型")
@RestController
@Validated
@RequestMapping("/goods/type")
public class TypeController implements GoodTypeInfoApis {
    @Resource
    GoodsTypeService goodsTypeService;
    @ApiOperation(value = "查询简单信息")
    @GetMapping("find-simple-type")
    @Override
    public JsonVO<PageDTO<SimpleTypeVO>> findSimpleType(@Valid PageQuery pageQuery, BindingResult result) {
        PageDTO<SimpleTypeVO> simpleType = goodsTypeService.findSimpleType(pageQuery.getPageIndex(), pageQuery.getPageSize());
        return JsonVO.success(simpleType);
    }
    @ApiOperation(value = "查询详细信息")
    @GetMapping("find-detailed-type")
    @Override
    public JsonVO<DetailedTypeVO> findDetailedType(@Valid GoodsTypeIdQuery attrId, BindingResult result) {

        DetailedTypeVO detailedType = goodsTypeService.findDetailedType(attrId.getAttrId());
        if(detailedType==null) return JsonVO.create(null,9999,"查询结果为空");
        return JsonVO.success(detailedType);
    }
    @ApiOperation("修改详细信息")
    @PostMapping(value = "modify-detailed-type")
    @Override
    public JsonVO<Boolean> modifyDetailedType(@Valid @RequestBody ModifyTypeDTO typeDTO,BindingResult result) {
        Boolean res = goodsTypeService.modifyTypeAttr(typeDTO);
        return JsonVO.success(res);
    }
    @ApiOperation("删除类型")
    @PostMapping("delete-type")
    @Override
    public JsonVO<String> deleteType(@Valid GoodsTypeIdQuery attrId,BindingResult result) {
        Boolean res = goodsTypeService.deleteType(attrId.getAttrId());
        if(res) return JsonVO.success("删除成功");
        else return JsonVO.fail("删除失败,数据不存在");
    }
    @ApiOperation("添加类型")
    @PostMapping("add-type")
    @Override
    public JsonVO<Boolean> addDetailedType(@Valid @RequestBody AddNewTypeDTO addNewTypeDTO, BindingResult result) {
        Boolean res = goodsTypeService.addType(addNewTypeDTO);
        return JsonVO.success(res);
    }
}
