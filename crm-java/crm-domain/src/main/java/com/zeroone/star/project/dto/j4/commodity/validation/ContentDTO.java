package com.zeroone.star.project.dto.j4.commodity.validation;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author 骇客老薛
 * @date 2023/10/29 22:17
 * com.zeroone.star.project.dto.j4.commodity.validation
 */
@Data
@ApiModel("商品详细信息DTO")
public class ContentDTO{
    @ApiModelProperty(value = "商品详细信息", example = "这是一个商品", required = true)
    private String content;
}
