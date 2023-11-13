package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * <p>
 * 付款记录
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("fin_pay_record")
public class FinPayRecordEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "record_id", type = IdType.AUTO)
    private Integer recordId;

    /**
     * 关联付款记划
     */
    private Integer planId;

    /**
     * 采购订单号
     */
    private Integer contractId;

    private String contractName;

    /**
     * 供应商号
     */
    private Integer supplierId;

    private String supplierName;

    /**
     * 关联帐号
     */
    private Integer bankId;

    private Date payDate;

    private BigDecimal money;

    private BigDecimal zeroMoney;

    private Integer stages;

    private String intro;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;


}
