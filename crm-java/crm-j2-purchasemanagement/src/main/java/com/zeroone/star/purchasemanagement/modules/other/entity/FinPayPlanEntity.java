package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * <p>
 * 付款计划表
 * </p>
 *
 * @author 汐
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("fin_pay_plan")
public class FinPayPlanEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "plan_id", type = IdType.AUTO)
    private Integer planId;

    /**
     * 采购订单号
     */
    private Integer contractId;

    /**
     * 采购合同名称
     */
    private String contractName;

    /**
     * 供应商号
     */
    private Integer supplierId;

    /**
     * 供应商名称
     */
    private String supplierName;

    /**
     * 关联银行帐号
     */
    private Integer bankId;

    /**
     * 金额
     */
    private Integer money;

    /**
     * 计划付款时间
     */
    private LocalDate planDate;

    /**
     * 其次
     */
    private Integer stages;

    private String ifpay;

    private String intro;

    private Integer createUserId;

    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;


}
