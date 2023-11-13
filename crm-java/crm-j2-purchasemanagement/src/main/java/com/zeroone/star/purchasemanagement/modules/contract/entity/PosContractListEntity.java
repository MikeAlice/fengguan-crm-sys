package com.zeroone.star.purchasemanagement.modules.contract.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * <p>
 * 采购订单商品表
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("pos_contract_list")
public class PosContractListEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 订单项ID
     */
    @TableId(value = "list_id", type = IdType.AUTO)
    private Integer listId;

    /**
     * 合同ID
     */
    private Integer contractId;

    /**
     * 商品ID
     */
    private Integer goodsId;

    /**
     * 商品名称
     */
    private String goodsName;

    /**
     * skuID
     */
    private Integer skuId;

    /**
     * sku名称
     */
    private String skuName;

    /**
     * 商品价格
     */
    private BigDecimal salePrice;

    /**
     * 商品成本价
     */
    private BigDecimal costPrice;

    /**
     * 购买数量
     */
    private String num;

    /**
     * 入库数据
     */
    private String intoNum;

    /**
     * 未入库数量
     */
    private String oweNum;

    /**
     * 未入库金额
     */
    private BigDecimal oweMoney;

    /**
     * 调整金额
     */
    private BigDecimal adjustMoney;

    /**
     * 商品总价
     */
    private BigDecimal goodsMoney;

    /**
     * 商品图片
     */
    private Integer goodsPicture;

    /**
     * 备注
     */
    private String remarks;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;


}
