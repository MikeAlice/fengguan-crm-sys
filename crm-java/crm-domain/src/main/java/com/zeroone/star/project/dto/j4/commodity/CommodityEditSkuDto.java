package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.DecimalMin;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.math.BigDecimal;

/**
 * @program: crm-java
 * @ClassName CommodityEditSkuDto
 * @description:
 * @author: zlw
 * @create: 2023-10-24 23:28
 * @Version 1.0
 **/

@Data
@ApiModel(value = "商品修改SKU数据传输对象")
public class CommodityEditSkuDto {

    @NotNull
    @ApiModelProperty(value = "商品id", example = "111", required = true)
    private Integer goodsId;

    @DecimalMin(value = "0",message = "必须大于等于0")
    @ApiModelProperty(value = "销售价格", example = "300.00", required = true)
    private BigDecimal salePrice;

    @DecimalMin(value = "0",message = "必须大于等于0")
    @ApiModelProperty(value = "市场价格", example = "200.00", required = true)
    private BigDecimal marketPrice;
}
