package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 品牌表
 * </p>
 *
 * @author diwu
 * @since 2023-10-23
 */
@Data
@TableName("fly_goods_brand")
public class FlyGoodsBrand implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 索引ID
     */
    @TableId(value = "brand_id", type = IdType.AUTO)
    private Long brandId;

    /**
     * 店铺ID
     */
    private Integer shopId;

    /**
     * 品牌名称
     */
    private String brandName;

    /**
     * 品牌首字母
     */
    private String brandInitial;

    /**
     * 图片
     */
    private String brandPic;

    /**
     * 推荐，0为否，1为是，默认为0
     */
    private Boolean brandRecommend;


    /**
     *   品牌分类
     */
    private Integer sort;

    /**
     * 类别名称
     */
    private String brandCategoryName;

    /**
     * 所属分类id组
     */
    private String categoryIdArray;

    /**
     * 品牌推荐广告
     */
    private String brandAds;

    /**
     * 品牌所属分类名称
     */
    private String categoryName;

    /**
     * 一级分类ID
     */
    @TableField("category_Id_1")
    private Integer categoryId1;

    /**
     * 二级分类ID
     */
    @TableField("category_Id_2")
    private Integer categoryId2;

    /**
     * 三级分类ID
     */
    @TableField("category_Id_3")
    private Integer categoryId3;


}
