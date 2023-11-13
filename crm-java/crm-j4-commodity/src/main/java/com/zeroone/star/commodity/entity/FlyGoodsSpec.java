package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 商品属性（规格）表
 * </p>
 *
 * @author Tezz
 * @since 2023-10-25
 */
@Getter
@Setter
@TableName("fly_goods_spec")
public class FlyGoodsSpec implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 属性ID
     */
    @TableId(value = "spec_id", type = IdType.AUTO)
    private Integer specId;

    /**
     * 店铺ID
     */
    private Integer shopId;

    /**
     * 属性名称
     */
    private String specName;

    /**
     * 是否可视
     */
    private Boolean visible;

    /**
     * 排序
     */
    private Integer sort;

    /**
     * 展示方式 1 文字 2 颜色 3 图片
     */
    private Integer showType;

    /**
     * 创建日期
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 是否参与筛选 0 不参与 1 参与
     */
    private Boolean isScreen;

    /**
     * 属性说明
     */
    private String specDes;

    /**
     * 商品关联id
     */
    private Integer goodsId;


}
