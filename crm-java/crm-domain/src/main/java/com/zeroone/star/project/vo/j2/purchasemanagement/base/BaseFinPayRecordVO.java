package com.zeroone.star.project.vo.j2.purchasemanagement.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * 付款记录基本vo模型
 *
 * @author j2
 * @since 2023/10/29
 */
@Data
@ApiModel(value = "付款记录基本vo模型")
public class BaseFinPayRecordVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "付款记录ID")
    private Integer recordId;

    @ApiModelProperty(value = "关联付款计划ID")
    private Integer planId;

    @ApiModelProperty(value = "采购订单号")
    private Integer contractId;

    @ApiModelProperty(value = "采购合同名称")
    private String contractName;

    @ApiModelProperty(value = "供应商号")
    private Integer supplierId;

    @ApiModelProperty(value = "供应商名称")
    private String supplierName;

    @ApiModelProperty(value = "关联帐号")
    private Integer bankId;

    @ApiModelProperty(value = "支付日期")
    private Date payDate;

    @ApiModelProperty(value = "支付金额")
    private BigDecimal money;

    @ApiModelProperty(value = "去零金额")
    private BigDecimal zeroMoney;

    @ApiModelProperty(value = "期次")
    private Integer stages;

    @ApiModelProperty(value = "介绍")
    private String intro;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;

    @ApiModelProperty(value = "创建用户ID")
    private Integer createUserId;
}
