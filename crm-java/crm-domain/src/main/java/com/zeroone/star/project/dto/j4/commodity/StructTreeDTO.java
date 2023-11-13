package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Qianyue
 * @Date 2023.10.23 21:36
 **/
@Data
public class StructTreeDTO {

    @ApiModelProperty(value = "商品分类简称", example = "日用品")
    private String shortName;
    @ApiModelProperty(value = "商品分类id", example = "0")
    private Integer categoryId;

    @ApiModelProperty(value = "一级分类id", example = "1")
    private Integer categoryId1;

    @ApiModelProperty(value = "二级分类id", example = "2")
    private Integer categoryId2;

    @ApiModelProperty(value = "三级分类id", example = "3")
    private Integer categoryId3;
}
