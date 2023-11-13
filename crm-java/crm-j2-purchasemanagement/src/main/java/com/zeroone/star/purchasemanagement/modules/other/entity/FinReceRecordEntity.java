package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * <p>
 * 回款记录
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("fin_rece_record")
public class FinReceRecordEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "record_id", type = IdType.AUTO)
    private Integer recordId;

    /**
     * 合同订单号
     */
    private Integer contractId;

    private String contractName;

    private Integer planId;

    /**
     * 客户号
     */
    private Integer customerId;

    private String customerName;

    /**
     * 关联帐号
     */
    private Integer bankId;

    /**
     * 金额
     */
    private BigDecimal money;

    /**
     * 去零金额
     */
    private BigDecimal zeroMoney;

    /**
     * 计划回款时间
     */
    private Date backDate;

    /**
     * 期次
     */
    private Integer stages;

    /**
     * 关联业务类型
     */
    private String busType;

    private String intro;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;


}
