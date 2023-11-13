package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 库存清单
 * </p>
 *
 * @author zhenglw
 * @since 2023-10-24
 */
@Getter
@Setter
@TableName("stock_goods_sku")
public class StockGoodsSku implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 表序号
     */
    @TableId(value = "stock_goods_sku_id", type = IdType.AUTO)
    private Integer stockGoodsSkuId;

    /**
     * skuID
     */
    private Integer skuId;

    /**
     * 仓库编号
     */
    private Integer storeId;

    /**
     * 商品编号
     */
    private Integer goodsId;

    /**
     * 商品名称
     */
    private String goodsName;

    /**
     * SKU名称
     */
    private String skuName;

    /**
     * 销售价格
     */
    private BigDecimal salePrice;

    /**
     * 成本价
     */
    private BigDecimal costPrice;

    /**
     * 成本总金额
     */
    private BigDecimal totalCostMoney;

    /**
     * 销售总金额
     */
    private BigDecimal totalSaleMoney;

    /**
     * 利润总金额
     */
    private BigDecimal totalProfitMoney;

    /**
     * 库存
     */
    private Integer stock;

    /**
     * 商家编码
     */
    private String code;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;


}
