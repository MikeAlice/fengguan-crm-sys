package com.zeroone.star.purchasemanagement.modules.contract.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * <p>
 * 采购合同
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("pos_contract")
public class PosContractEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "contract_id", type = IdType.AUTO)
    private Integer contractId;

    /**
     * 合同编号
     */
    private String contractNo;

    private Integer supplierId;

    private Integer linkmanId;

    private Integer chanceId;

    /**
     * 关联网站
     */
    private Integer websiteId;

    /**
     * 采购时间
     */
    private Date startDate;

    /**
     * 预订到货时间
     */
    private Date endDate;

    /**
     * 我方联系人
     */
    private Integer ourUserId;

    /**
     * 合同金额
     */
    private BigDecimal money;

    /**
     * 商品金额
     */
    private BigDecimal goodsMoney;

    /**
     * 去零金额
     */
    private BigDecimal zeroMoney;

    /**
     * 回款金额
     */
    private BigDecimal backMoney;

    /**
     * 欠款金额
     */
    private BigDecimal oweMoney;

    /**
     * 支付金额
     */
    private BigDecimal payMoney;

    /**
     * 未支付金额
     */
    private BigDecimal unpaidMoney;

    /**
     * 开票金额
     */
    private BigDecimal invoiceMoney;

    /**
     * 订单主题
     */
    private String title;

    /**
     * 订单介绍
     */
    private String intro;

    /**
     * 1=临时单，2=执行，3=完成，4=撤消
     */
    private Integer status;

    /**
     * 回款状态，1=未付，2=部分，3=全部
     */
    private Integer backStatus;

    /**
     * 支付状态，1=未付，2=部分，3=全部
     */
    private Integer payStatus;

    /**
     * 交付状态，-1=不需要，1=需要，2=录入明细，3=待入库，4=部分，5=全部
     */
    private Integer deliverStatus;

    /**
     * 开票状态 0=不需要，1=需要，2=部分，3=全部
     */
    private Integer invoiceStatus;

    /**
     * 收货状态，1=需要，2=录入明细，3=待入库，4=部分，5=全部
     */
    private Integer receStatus;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;


}
