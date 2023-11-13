package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 开票记录、
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("fin_invoice_pay")
public class FinInvoicePayEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "record_id", type = IdType.AUTO)
    private Integer recordId;

    /**
     * 合同订单号
     */
    private Integer contractId;

    private String contractName;

    /**
     * 客户号
     */
    private Integer customerId;

    private String customerName;

    private Integer money;

    /**
     * 开票时间
     */
    private Date payDate;

    private Integer stages;

    private String invoiceNo;

    private String name;

    /**
     * 订单类型
     */
    private String busType;

    private String intro;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;


}
