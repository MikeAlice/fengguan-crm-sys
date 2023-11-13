package com.zeroone.star.project.dto.j2.purchasemanagement;

import com.zeroone.star.project.vo.j2.purchasemanagement.base.BasePosContractVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.List;


@Data
@ApiModel(value = "下拉列表-采购合同")
public class ContractSelectDTO implements Serializable {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty("采购合同列表")
    private List<BasePosContractVO> contracts;
}
