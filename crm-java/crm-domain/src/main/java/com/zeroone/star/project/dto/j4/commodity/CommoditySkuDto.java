package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @program: crm-java
 * @ClassName CommoditySkuDto
 * @description:
 * @author: zlw
 * @create: 2023-10-24 09:20
 * @Version 1.0
 **/

@Data
@ApiModel(value = "商品新增SKU数据传输对象")
public class CommoditySkuDto {

    @ApiModelProperty(value = "商品id", example = "uuid", required = true)
    private String goodsId;
    @ApiModelProperty(value = "商品名称", example = "老人鞋子", required = true)
    private String goodsName;
    @ApiModelProperty(value = "商品规格", example = "颜色:白色,尺寸:35码", required = true)
    private String goodsSpecifications;
    @ApiModelProperty(value = "库存", example = "4", required = true)
    private Integer stock;
    @ApiModelProperty(value = "销售价格", example = "300.00", required = true)
    private BigDecimal salePrice;
    @ApiModelProperty(value = "市场价格", example = "200.00", required = true)
    private BigDecimal marketPrice;
    @ApiModelProperty(value = "成本单价", example = "-200.00", required = true)
    private BigDecimal costPrice;
    @ApiModelProperty(value = "成本总金额", example = "-800.00", required = true)
    private BigDecimal totalCostMoney;
    @ApiModelProperty(value = "预计利润", example = "320.00", required = true)
    private BigDecimal totalProfitMoney;
}
