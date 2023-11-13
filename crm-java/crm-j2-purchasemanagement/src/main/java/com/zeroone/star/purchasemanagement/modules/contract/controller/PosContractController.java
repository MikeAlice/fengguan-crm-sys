package com.zeroone.star.purchasemanagement.modules.contract.controller;


import com.zeroone.star.project.dto.j2.purchasemanagement.AddContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ContractSelectDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ModifyContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.SelectContractDTO;
import com.zeroone.star.project.j2.purchasemanagement.PosContractApis;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListWithPageConditionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.*;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 * 采购合同 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@RestController
@RequestMapping("/contract/pos-contract")
@Api(tags = "采购合同接口")
public class PosContractController implements PosContractApis {
    @Autowired
    private PosContractService posContractService;

    @PostMapping("get-contract-list-with-page-condition")
    @ApiOperation(value = "获取合同列表 (分页+条件)")
    @Override
    public JsonVO<GetContractListWithPageConditionVO> getContractListWithPageCondition(@RequestBody GetContractListWithPageConditionQuery getContractListWithPageConditionQuery) {
        GetContractListWithPageConditionVO result = posContractService.getContractListWithPageCondition(getContractListWithPageConditionQuery);
        return JsonVO.success(result);
    }

    @GetMapping("get-contract-detail")
    @ApiOperation(value = "获取合同详情")
    @Override
    public JsonVO<GetContractDetailVO> getContractDetail(@ApiParam(value = "合同ID", required = true) @RequestParam Integer contractId) {
        GetContractDetailVO result = posContractService.getContractDetail(contractId);
        return JsonVO.success(result);
    }

    @Override
    @GetMapping("get-contract-inventory")
    @ApiOperation(value = "获取合同清单")
    public JsonVO<GetContractInventoryVO> getContractInventory(@ApiParam(value = "合同ID", required = true) @RequestParam Integer contractId) {
        return JsonVO.success(posContractService.getContractInventory(contractId));
    }

    @PostMapping("modify-contract")
    @ApiOperation(value = "修改采购合同基本信息")
    @Override
    public JsonVO<String> modifyContract(@Valid @RequestBody ModifyContractDTO modifyContractDTO) {
        posContractService.updateContract(modifyContractDTO);
        return JsonVO.success("修改采购合同基本信息成功");
    }

    @PostMapping("add-contract")
    @ApiOperation(value = "添加采购合同")
    @Override
    public JsonVO<String> addContract(@Valid @RequestBody AddContractDTO addContractDTO) {
        posContractService.saveContract(addContractDTO);
        return JsonVO.success("添加合同信息成功");
    }

    @GetMapping("getContractNo")
    @ApiOperation(value = "获取合同唯一编号")
    @Override
    public JsonVO<GetContractNoVO> getContractNo() {
        return JsonVO.success(posContractService.getContractNo());
    }

    @GetMapping("export-contract")
    @ApiOperation(value = "导出采购合同")
    @Override
    public JsonVO<ExportContractVO> exportContract(@ApiParam(value = "合同ID集合") @RequestParam List<Integer> contractIds) throws Exception {
        ExportContractVO exportContractVO=posContractService.exportContract(contractIds);
        return JsonVO.success(exportContractVO);
    }

    @PostMapping("pos_contract_select_pay")
    @ApiOperation("下拉列表-获取采购合同信息")
    @Override
    public JsonVO<ContractSelectDTO> selectContractPay(@RequestBody SelectContractDTO dto){
        return JsonVO.success(posContractService.selectContract(dto));
    }

}

