package com.zeroone.star.project.dto.j2.purchasemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;

@Data
@ApiModel("下拉列表-获取采购合同")
public class SelectContractDTO {
    @NotNull(message = "供应商id不能为空")
    @ApiModelProperty(value = "供应商id")
    private Integer supplierId;
    @ApiModelProperty(value = "采购合同标题")
    private String title;
}
