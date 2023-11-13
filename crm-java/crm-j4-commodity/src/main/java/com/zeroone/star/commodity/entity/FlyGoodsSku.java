package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 商品sku规格价格信息表
 * </p>
 *
 * @author zhenglw
 * @since 2023-10-24
 */
@Getter
@Setter
@TableName("fly_goods_sku")
public class FlyGoodsSku implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 表序号
     */
    @TableId(value = "sku_id", type = IdType.AUTO)
    private Integer skuId;

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
     * 属性和属性值 id串 attribute + attribute value 表ID分号分隔
     */
    private String skuValueItems;

    /**
     * 属性和属性值id串组合json格式
     */
    private String skuValueItemsFormat;

    /**
     * 市场价
     */
    private BigDecimal marketPrice;

    /**
     * 销售价格
     */
    private BigDecimal salePrice;

    /**
     * 价格
     */
    private BigDecimal price;

    /**
     * 促销价格
     */
    private BigDecimal promotePrice;

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
     * 如果是第一个sku编码, 可以加图片
     */
    private Integer picture;

    /**
     * 商家编码
     */
    private String code;

    /**
     * 商品二维码
     */
    private String qRcode;

    /**
     * 创建时间
     */
    private LocalDateTime createDate;

    /**
     * 修改时间
     */
    private LocalDateTime updateDate;


}
