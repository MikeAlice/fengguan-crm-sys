package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

/**
 * @author zhairenhao
 * @date 2023/10/27 9:59
 * @description
 */
@Getter
@Setter
@TableName("fly_goods_img")
public class FlyGoodsImg {

    /**
     * ID
     */
    @TableId(value = "img_id", type = IdType.AUTO)
    private Integer imgId;

    /**
     * 商品ID
     */
    private Integer goodsId;

    /**
     * 图片路径
     */
    private String imgPath;
}
