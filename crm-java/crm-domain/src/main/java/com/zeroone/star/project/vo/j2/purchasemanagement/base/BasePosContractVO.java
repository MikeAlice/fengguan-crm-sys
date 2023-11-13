package com.zeroone.star.project.vo.j2.purchasemanagement.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * 采购订单基本vo模型
 *
 * @author j2
 * @since 2023/10/29
 */
@Data
@ApiModel(value = "采购订单基本vo模型")
public class BasePosContractVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "采购合同ID")
    private Integer contractId;

    @ApiModelProperty(value = "合同编号")
    private String contractNo;

    @ApiModelProperty(value = "供应商ID")
    private Integer supplierId;

    @ApiModelProperty(value = "供应商联系人ID")
    private Integer linkmanId;

    @ApiModelProperty(value = "销售机会ID")
    private Integer chanceId;

    @ApiModelProperty(value = "关联网站ID")
    private Integer websiteId;

    @ApiModelProperty(value = "采购时间")
    private Date startDate;

    @ApiModelProperty(value = "预订到货时间")
    private Date endDate;

    @ApiModelProperty(value = "我方联系人")
    private Integer ourUserId;

    @ApiModelProperty(value = "合同金额")
    private BigDecimal money;

    @ApiModelProperty(value = "商品金额")
    private BigDecimal goodsMoney;

    @ApiModelProperty(value = "去零金额")
    private BigDecimal zeroMoney;

    @ApiModelProperty(value = "回款金额")
    private BigDecimal backMoney;

    @ApiModelProperty(value = "欠款金额")
    private BigDecimal oweMoney;

    @ApiModelProperty(value = "支付金额")
    private BigDecimal payMoney;

    @ApiModelProperty(value = "未支付金额")
    private BigDecimal unpaidMoney;

    @ApiModelProperty(value = "开票金额")
    private BigDecimal invoiceMoney;

    @ApiModelProperty(value = "订单主题")
    private String title;

    @ApiModelProperty(value = "订单介绍")
    private String intro;

    @ApiModelProperty(value = "1=临时单，2=执行，3=完成，4=撤消")
    private Integer status;

    @ApiModelProperty(value = "回款状态，1=未付，2=部分，3=全部")
    private Integer backStatus;

    @ApiModelProperty(value = "支付状态，1=未付，2=部分，3=全部")
    private Integer payStatus;

    @ApiModelProperty(value = "交付状态，-1=不需要，1=需要，2=录入明细，3=待入库，4=部分，5=全部")
    private Integer deliverStatus;

    @ApiModelProperty(value = "开票状态 0=不需要，1=需要，2=部分，3=全部")
    private Integer invoiceStatus;

    @ApiModelProperty(value = "收货状态，1=需要，2=已录明细，3=待入库，4=部分，5=全部")
    private Integer receStatus;

    @ApiModelProperty(value = "创建用户ID")
    private Integer createUserId;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;
}
