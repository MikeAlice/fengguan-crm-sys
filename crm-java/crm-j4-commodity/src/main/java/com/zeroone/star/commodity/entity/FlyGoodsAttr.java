package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 商品相关属性
 * </p>
 *
 * @author Ak5ma1
 * @since 2023-10-24
 */
@Getter
@Setter
@TableName("fly_goods_attr")
public class FlyGoodsAttr implements Serializable {
    @Override
    public String toString() {
        return "FlyGoodsAttr{" +
                "attrId=" + attrId +
                ", attrName='" + attrName + '\'' +
                ", visible=" + visible +
                ", specIdArray='" + specIdArray + '\'' +
                ", sort=" + sort +
                ", createTime=" + createTime +
                ", modifyTime=" + modifyTime +
                ", brandIdArray='" + brandIdArray + '\'' +
                '}';
    }

    public void setAttrId(Integer attrId) {
        this.attrId = attrId;
    }

    public void setAttrName(String attrName) {
        this.attrName = attrName;
    }

    public void setVisible(Boolean visible) {
        this.visible = visible;
    }

    public void setSpecIdArray(String specIdArray) {
        this.specIdArray = specIdArray;
    }

    public void setSort(Integer sort) {
        this.sort = sort;
    }

    public void setCreateTime(Integer createTime) {
        this.createTime = createTime;
    }

    public void setModifyTime(Integer modifyTime) {
        this.modifyTime = modifyTime;
    }

    public void setBrandIdArray(String brandIdArray) {
        this.brandIdArray = brandIdArray;
    }

    private static final long serialVersionUID = 1L;

    /**
     * 商品属性ID
     */
    @TableId(value = "attr_id", type = IdType.AUTO)
    private Integer attrId;

    /**
     * 属性名称
     */
    private String attrName;

    /**
     * 是否使用
     */
    private Boolean visible;

    /**
     * 关联规格
     */
    private String specIdArray;

    private Integer sort;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private Integer createTime;

    /**
     * 修改时间
     */
    private Integer modifyTime;

    /**
     * 关联品牌
     */
    private String brandIdArray;


}
