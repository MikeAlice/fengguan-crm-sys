package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Qianyue
 * @Date 2023 10 23 14 29
 **/
@Data
@ApiModel(value = "获取商品分类列表")
public class CategoryListDTO {
    @ApiModelProperty(value = "商品名称", example = "日用品")
    private String goodsName;

    @ApiModelProperty(value = "商品主图", example = "https://xxx/xxx.jpg")
    private String defaultPic;

    @ApiModelProperty(value = "商品介绍", example = "日用品一级分类")
    private String introduction;

    @ApiModelProperty(value = "排序字段", example = "100")
    private Integer sort;

    @ApiModelProperty(value = "分类状态:是否启用", example = "1")
    private Integer state;

}
