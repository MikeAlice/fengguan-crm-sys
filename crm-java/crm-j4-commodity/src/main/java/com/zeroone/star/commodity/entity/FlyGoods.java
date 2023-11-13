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
 * 商品表
 * </p>
 *
 * @author zhairenhao
 * @since 2023-10-24
 */
@Getter
@Setter
@TableName("fly_goods")
public class FlyGoods implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 商品id(SKU)
     */
    @TableId(value = "goods_id", type = IdType.AUTO)
    private Integer goodsId;

    /**
     * 商品名称
     */
    private String goodsName;

    /**
     * 店铺id
     */
    private Integer shopId;

    /**
     * 商品分类id
     */
    private Integer categoryId;

    /**
     * 一级分类id
     */
    @TableField("category_id_1")
    private Integer categoryId1;

    /**
     * 二级分类id
     */
    @TableField("category_id_2")
    private Integer categoryId2;

    /**
     * 三级分类id
     */
    @TableField("category_id_3")
    private Integer categoryId3;

    /**
     * 品牌id
     */
    private Integer brandId;

    /**
     * 店铺分类id 首尾用,隔开
     */
    private String groupIdArray;

    /**
     * 促销类型 0无促销，1团购，2限时折扣
     */
    private Integer promotionType;

    /**
     * 实物或虚拟商品标志 1实物商品 0 虚拟商品 2 F码商品
     */
    private Integer goodsType;

    /**
     * 市场价
     */
    private BigDecimal marketPrice;

    /**
     * 销售价格
     */
    private BigDecimal salePrice;

    /**
     * 成本价
     */
    private BigDecimal costPrice;

    /**
     * 商品原价格
     */
    private BigDecimal price;

    /**
     * 商品促销价格
     */
    private BigDecimal promotionPrice;

    /**
     * 购买商品赠送积分
     */
    private Integer givePoint;

    /**
     * 参与会员折扣
     */
    private Integer isMemberDiscount;

    /**
     * 运费 0为免运费
     */
    private BigDecimal shippingFee;

    /**
     * 售卖区域id 物流模板id  ns_order_shipping_fee 表id
     */
    private Integer shippingFeeId;

    /**
     * 限购 0 不限购
     */
    private Integer maxBuy;

    /**
     * 商品点击数量
     */
    private Integer clicks;

    /**
     * 库存预警值
     */
    private Integer minStockAlarm;

    /**
     * 销售数量
     */
    private Integer sales;

    /**
     * 收藏数量
     */
    private Integer collects;

    /**
     * 好评星级
     */
    private Integer star;

    /**
     * 评价数
     */
    private Integer evaluates;

    /**
     * 分享数
     */
    private Integer shares;

    /**
     * 一级地区id
     */
    private Integer provinceId;

    /**
     * 二级地区id
     */
    private Integer cityId;

    /**
     * 商品主图
     */
    private String defaultpic;

    /**
     * 商品关键词
     */
    private String keywords;

    /**
     * 商品简介，促销语
     */
    private String introduction;

    /**
     * 商品详情
     */
    private String description;

    /**
     * 商品详细内容
     */
    private String content;

    /**
     * 商家编号
     */
    private String code;

    /**
     * 是否热销商品
     */
    private Integer isHot;

    /**
     * 是否推荐0=不推荐，1=推荐
     */
    private Integer isRecommend;

    /**
     * 是否新品
     */
    private Integer isNew;

    /**
     * 是否开具增值税发票 1是，0否
     */
    private Integer isBill;

    /**
     * 商品状态 0下架，1正常，10违规（禁售）
     */
    private Integer state;

    /**
     * 排序
     */
    private Integer sort;

    /**
     * 商品图片序列
     */
    private String imgIdArray;

    /**
     * 商品sku应用图片列表  属性,属性值，图片ID
     */
    private String skuImgArray;

    /**
     * 实物与描述相符（根据评价计算）
     */
    private Float matchPoint;

    /**
     * 实物与描述相符（根据评价计算）百分比
     */
    private Float matchRatio;

    /**
     * 实际销量
     */
    private Integer realSales;

    /**
     * 商品类型
     */
    private Integer goodsAttributeId;

    /**
     * 商品规格
     */
    private String goodsSpecFormat;

    /**
     * 商品重量
     */
    private BigDecimal goodsWeight;

    /**
     * 商品体积
     */
    private BigDecimal goodsVolume;

    /**
     * 计价方式1.重量2.体积3.计件
     */
    private Integer shippingFeeType;

    private String extendCategoryId;

    @TableField("extend_category_id_1")
    private String extendCategoryId1;

    @TableField("extend_category_id_2")
    private String extendCategoryId2;

    @TableField("extend_category_id_3")
    private String extendCategoryId3;

    /**
     * 供货商id
     */
    private Integer supplierId;

    /**
     * 上下架时间
     */
    private LocalDateTime saleDate;

    /**
     * 商品添加时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 商品编辑时间
     */
    private LocalDateTime updateTime;

    /**
     * 最少买几件
     */
    private Integer minBuy;

    /**
     * 虚拟商品类型id
     */
    private Integer virtualGoodsTypeId;

    /**
     * 生产日期
     */
    private Integer productionDate;

    /**
     * 保质期
     */
    private String shelfLife;

    /**
     * 商品视频地址，不为空时前台显示视频
     */
    private String goodsVideoAddress;

    /**
     * pc端商品自定义模板
     */
    private String pcCustomTemplate;

    /**
     * wap端商品自定义模板
     */
    private String wapCustomTemplate;

    /**
     * 积分抵现最大可用积分数 0为不可使用
     */
    private Integer maxUsePoint;

    /**
     * 是否支持预售
     */
    private Integer isOpenPresell;

    /**
     * 预售发货时间
     */
    private Integer presellTime;

    /**
     * 预售发货天数
     */
    private Integer presellDay;

    /**
     * 预售发货方式1. 按照预售发货时间 2.按照预售发货天数
     */
    private Integer presellDeliveryType;

    /**
     * 预售金额
     */
    private BigDecimal presellPrice;

    /**
     * 商品单位
     */
    private String goodsUnit;


}
