package com.zeroone.star.project.dto.j4.commodity.maintenance;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * @author zhairenhao
 * @date 2023/10/26 15:02
 * @description 分页获取商品列表返回数据对象
 */
@Data
@ApiModel(value = "分页获取商品列表返回数据对象")
public class GoodsListDTO {

    @ApiModelProperty(value = "商品id", example = "74")
    private Integer goodsId;

    @ApiModelProperty(value = "商品图片", example = "1.jpg")
    private String picture;

    @ApiModelProperty(value = "价格", example = "999.99")
    private BigDecimal price;

    @ApiModelProperty(value = "总库存", example = "1355")
    private Integer totalStock;

    @ApiModelProperty(value = "销售量", example = "1355")
    private Integer sales;

    @ApiModelProperty(value = "创建时间", example = "2023-10-27 15:28:00")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "商家编码", example = "10086")
    private String code;

    @ApiModelProperty(value = "排序", example = "1")
    private Integer sort;

}
