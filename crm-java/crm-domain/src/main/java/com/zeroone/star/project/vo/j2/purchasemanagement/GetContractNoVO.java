package com.zeroone.star.project.vo.j2.purchasemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel(value="获取合同唯一编号")
public class GetContractNoVO implements Serializable{
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "合同编号")
    private String contractNo;
}
