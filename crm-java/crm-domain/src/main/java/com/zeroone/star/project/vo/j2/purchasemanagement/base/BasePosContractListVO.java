package com.zeroone.star.project.vo.j2.purchasemanagement.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * 采购明细基本vo模型
 *
 * @author j2
 * @since 2023/10/29
 */
@Data
@ApiModel(value = "采购明细基本vo模型")
public class BasePosContractListVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "采购明细ID")
    private Integer listId;

    @ApiModelProperty(value = "合同ID")
    private Integer contractId;

    @ApiModelProperty(value = "商品ID")
    private Integer goodsId;

    @ApiModelProperty(value = "商品名称")
    private String goodsName;

    @ApiModelProperty(value = "skuID")
    private Integer skuId;

    @ApiModelProperty(value = "sku名称")
    private String skuName;

    @ApiModelProperty(value = "商品价格")
    private BigDecimal salePrice;

    @ApiModelProperty(value = "商品成本价")
    private BigDecimal costPrice;

    @ApiModelProperty(value = "购买数量")
    private String num;

    @ApiModelProperty(value = "入库数据")
    private String intoNum;

    @ApiModelProperty(value = "未入库数量")
    private String oweNum;

    @ApiModelProperty(value = "未入库金额")
    private BigDecimal oweMoney;

    @ApiModelProperty(value = "调整金额")
    private BigDecimal adjustMoney;

    @ApiModelProperty(value = "商品总价")
    private BigDecimal goodsMoney;

    @ApiModelProperty(value = "商品图片")
    private Integer goodsPicture;

    @ApiModelProperty(value = "备注")
    private String remarks;

    @ApiModelProperty(value = "创建用户ID")
    private Integer createUserId;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;
}
