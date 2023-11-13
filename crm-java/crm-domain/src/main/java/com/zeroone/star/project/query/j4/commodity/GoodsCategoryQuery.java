package com.zeroone.star.project.query.j4.commodity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;

/**
 * @author Qianyue
 *查询商品分类条件对象
 * @Date 2023.10.23 20:54
 **/
public class GoodsCategoryQuery  {
    @ApiModelProperty(value = "商品分类简称", example = "日用品", required = true)
    private String shortName;
    @ApiModelProperty(value = "商品分类id", example = "1", required = true)
    private Integer categoryId;
}
