package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 收票记录
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("fin_invoice_rece")
public class FinInvoiceReceEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "record_id", type = IdType.AUTO)
    private Integer recordId;

    /**
     * 关联采购号
     */
    private Integer contractId;

    /**
     * 供应商号
     */
    private Integer supplierId;

    private String contractName;

    private String supplierName;

    private Integer money;

    /**
     * 收票时间
     */
    private Date receDate;

    private Integer stages;

    /**
     * 发票内容
     */
    private String name;

    /**
     * 发票编号
     */
    private String invoiceNo;

    private String intro;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;


}
