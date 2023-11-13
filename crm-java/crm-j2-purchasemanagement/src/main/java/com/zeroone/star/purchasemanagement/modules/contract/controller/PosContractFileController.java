package com.zeroone.star.purchasemanagement.modules.contract.controller;


import com.zeroone.star.project.dto.j2.purchasemanagement.PosContractFileDTO;
import com.zeroone.star.project.j2.purchasemanagement.PosContractFileApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 采购合同附件 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@RestController
@RequestMapping("/contract/pos-contract-file")
public class PosContractFileController implements PosContractFileApis {


    @ApiOperation(value = "添加合同附件")
    @Override
    public JsonVO<Void> addPosContractFile(PosContractFileDTO posContractFileDTO) {
        return null;
    }
}

