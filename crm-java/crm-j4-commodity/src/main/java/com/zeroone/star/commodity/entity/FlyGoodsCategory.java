package com.zeroone.star.commodity.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

import com.zeroone.star.project.dto.j4.commodity.AddGoodsCategoryDTO;
import com.zeroone.star.project.dto.j4.commodity.UpdateGoodsCategoryDTO;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 商品分类表
 * </p>
 *
 * @author 张二发
 * @since 2023-10-24
 */
@Getter
@Setter
@TableName("fly_goods_category")
public class FlyGoodsCategory implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "category_id", type = IdType.AUTO)
    private Integer categoryId;

    private String categoryName;

    /**
     * 商品分类简称 
     */
    private String shortName;

    private Integer parentId;

    private Integer level;

    /**
     * 是否显示  1 显示 0 不显示
     */
    private Integer visible;

    /**
     * 关联商品类型ID
     */
    private Integer attrId;

    /**
     * 关联类型名称
     */
    private String attrName;

    /**
     * 分类关键字用于seo
     */
    private String keywords;

    /**
     * 分类描述用于seo
     */
    private String description;

    private Integer sort;

    /**
     * 商品分类图片
     */
    private String categoryPic;

    /**
     * pc端商品分类自定义模板
     */
    private String pcCustomTemplate;

    /**
     * wap端商品分类自定义模板
     */
    private String wapCustomTemplate;

    public FlyGoodsCategory(){

    }

    public FlyGoodsCategory(AddGoodsCategoryDTO goodsCategoryDTO){
        categoryName = goodsCategoryDTO.getName();
        shortName = goodsCategoryDTO.getShortName();
        parentId = goodsCategoryDTO.getParentId();
        sort = goodsCategoryDTO.getSortIndex();
        description = goodsCategoryDTO.getDescription();
        keywords = goodsCategoryDTO.getKeywords();
    }

    public FlyGoodsCategory(UpdateGoodsCategoryDTO goodsCategoryDTO){
        categoryId = goodsCategoryDTO.getId();
        categoryName = goodsCategoryDTO.getName();
        shortName = goodsCategoryDTO.getShortName();
        parentId = goodsCategoryDTO.getParentId();
        sort = goodsCategoryDTO.getSortIndex();
        description = goodsCategoryDTO.getDescription();
        keywords = goodsCategoryDTO.getKeywords();

    }
}
