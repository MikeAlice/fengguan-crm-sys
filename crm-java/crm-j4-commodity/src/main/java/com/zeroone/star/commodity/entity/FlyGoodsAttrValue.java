package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 商品属性值
 * </p>
 *
 * @author Ak5ma1
 * @since 2023-10-24
 */

@Getter
@Setter
@TableName("fly_goods_attr_value")
public class FlyGoodsAttrValue implements Serializable {
    @Override
    public String toString() {
        return "FlyGoodsAttrValue{" +
                "attrValueId=" + attrValueId +
                ", attrId=" + attrId +
                ", attrValueName='" + attrValueName + '\'' +
                ", attrValueData='" + attrValueData + '\'' +
                ", type=" + type +
                ", sort=" + sort +
                ", search=" + isSearch +
                '}';
    }

    public void setAttrValueId(Integer attrValueId) {
        this.attrValueId = attrValueId;
    }

    public void setAttrId(Integer attrId) {
        this.attrId = attrId;
    }

    public void setAttrValueName(String attrValueName) {
        this.attrValueName = attrValueName;
    }

    public void setAttrValueData(String attrValueData) {
        this.attrValueData = attrValueData;
    }

    public void setType(Integer type) {
        this.type = type;
    }

    public void setSort(Integer sort) {
        this.sort = sort;
    }

    public boolean getSearch() {
        return isSearch;
    }

    public void setSearch(boolean search) {
        this.isSearch = search;
    }

    private static final long serialVersionUID = 1L;

    /**
     * 属性值ID
     */
    @TableId(value = "attr_value_id", type = IdType.AUTO)
    private Integer attrValueId;

    /**
     * 属性ID
     */
    @Getter
    private Integer attrId;

    /**
     * 属性值名称
     */
    @Getter
    private String attrValueName;

    /**
     * 属性对应相关数据
     */
    @Getter
    private String attrValueData;

    /**
     * 属性对应输入类型1.直接2.单选3.多选
     */
    @Getter
    private Integer type;

    /**
     * 排序号
     */
    @Getter
    private Integer sort;

    /**
     * 是否使用
     */
//    private Boolean search;
    @TableField(value = "is_search",javaType = true)
    private boolean isSearch;

}
