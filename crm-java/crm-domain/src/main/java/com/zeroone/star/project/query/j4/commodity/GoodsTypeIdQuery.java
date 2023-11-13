package com.zeroone.star.project.query.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;

@Data
@ApiModel("查询商品类型条件对象")
public class GoodsTypeIdQuery {
    @NotNull(message = "商品属性ID不能为空")
    @Min(value = 1,message = "最小为1")
    @ApiModelProperty(value = "商品属性ID", example = "1", required = true)
    private int attrId;
}
