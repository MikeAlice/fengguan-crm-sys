package com.zeroone.star.project.dto.j2.purchasemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 采购合同附件基本vo模型
 *
 */
@Data
@ApiModel(value = "采购合同附件基本Dto模型")
public class PosContractFileDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "采购合同附件ID")
    private Integer id;

    @ApiModelProperty(value = "合同ID")
    private Integer contractId;

    @ApiModelProperty(value = "文件名称")
    private String name;

    @ApiModelProperty(value = "类型")
    private String type;

    @ApiModelProperty(value = "备注")
    private String remarks;

    @ApiModelProperty(value = "文件路径")
    private String filepath;

    @ApiModelProperty(value = "创建用户ID")
    private Integer createUserId;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;
}
