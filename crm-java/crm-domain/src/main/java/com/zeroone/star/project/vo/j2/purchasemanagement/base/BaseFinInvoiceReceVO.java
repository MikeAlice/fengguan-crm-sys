package com.zeroone.star.project.vo.j2.purchasemanagement.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 收票记录基本vo模型
 *
 * @author j2
 * @since 2023/10/29
 */
@Data
@ApiModel(value = "收票记录基本vo模型")
public class BaseFinInvoiceReceVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "收票记录ID")
    private Integer recordId;

    @ApiModelProperty(value = "关联采购号")
    private Integer contractId;

    @ApiModelProperty(value = "供应商号")
    private Integer supplierId;

    @ApiModelProperty(value = "采购合同名称")
    private String contractName;

    @ApiModelProperty(value = "供应商名称")
    private String supplierName;

    @ApiModelProperty(value = "收票金额")
    private Integer money;

    @ApiModelProperty(value = "收票时间")
    private Date receDate;

    @ApiModelProperty(value = "期次")
    private Integer stages;

    @ApiModelProperty(value = "发票内容")
    private String name;

    @ApiModelProperty(value = "发票编号")
    private String invoiceNo;

    @ApiModelProperty(value = "介绍")
    private String intro;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;

    @ApiModelProperty(value = "创建用户ID")
    private Integer createUserId;
}
