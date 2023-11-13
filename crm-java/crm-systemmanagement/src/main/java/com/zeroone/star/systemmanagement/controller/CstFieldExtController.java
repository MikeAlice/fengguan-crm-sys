package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtDTO;
import com.zeroone.star.project.j1.systemmanagement.CstFieldExtApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanagement.service.ICstFieldExtService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 客户字段扩展表 前端控制器
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@RestController
@Api(tags = "字段扩展")
@RequestMapping("/systemmanagement")
public class CstFieldExtController implements CstFieldExtApis {

    @Resource
    private ICstFieldExtService cstFieldExtService;
    @Override
    @ApiOperation(value = "添加扩展字段")
    @PostMapping("add")
    public JsonVO<String> addCstFieldExt(CstFieldExtDTO dto) {
        return JsonVO.success(cstFieldExtService.addCstFieldExt(dto));
    }



    @Override
    @ApiOperation(value = "删除扩展字段")
    @DeleteMapping("remove-by-id")
    public JsonVO<String> removeCstFieldExt(
            @ApiParam(value = "扩展字段id",required = true) @RequestParam("id") Integer extId) {
        if (extId==null)return JsonVO.fail("字段为空");
        boolean isSuccess = cstFieldExtService.removeByIdExceptSysMsg(extId);
        if (isSuccess)return JsonVO.success("删除成功");
        else return JsonVO.fail("删除失败");
    }

    @Override
    @ApiOperation(value = "批量删除扩展字段")
    @DeleteMapping("remove-by-ids")
    public JsonVO<String> removeBatchCstFieldExt(
            @ApiParam(value = "扩展字段id列表",required = true) @RequestBody List<Integer> extIds) {
        if (extIds.isEmpty())return JsonVO.fail("删除字段列表为空");
        boolean isSuccess = cstFieldExtService.batchRemoveByIds(extIds);
        if (isSuccess)return JsonVO.success("删除成功");
        else return JsonVO.fail("删除失败");
    }
}

