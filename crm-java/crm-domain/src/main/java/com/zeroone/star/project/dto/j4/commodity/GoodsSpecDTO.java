package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author 骇客老薛
 * @date 2023/10/25 14:31
 * com.zeroone.star.project.dto.j4.commodity
 */

@Data
@ApiModel(value = "商品规格传输对象")
public class GoodsSpecDTO {

    @ApiModelProperty(value = "规格:0:颜色，1:尺寸，2:尺码", example = "1", required = true)
    private Integer spec;

    @ApiModelProperty(value = "规格值", example = "天空色或37码或37", required = true)
    private String specValue;
}
