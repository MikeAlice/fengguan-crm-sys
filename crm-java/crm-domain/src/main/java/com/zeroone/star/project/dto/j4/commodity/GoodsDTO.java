package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.beans.factory.annotation.Autowired;

import javax.validation.constraints.NotBlank;
import java.math.BigDecimal;
import java.util.List;

/**
 * @author zhairenhao
 * @date 2023/10/22 22:42
 * @description
 *
 *
 *
 *
 */
@Data
@ApiModel(value = "商品数据传输对象")
public class GoodsDTO {
    @ApiModelProperty(value = "商品名称", example = "假面骑士腰带", required = true)
    private String goodsName;
    @ApiModelProperty(value = "商品分类名称", example = "xxx", required = true)
    private String categoryName;
    @ApiModelProperty(value = "品牌id", example = "1", required = true)
    private Integer brandId;
    @ApiModelProperty(value = "商品关键词", example = "万代正版", required = true)
    private String keyWords;
    @ApiModelProperty(value = "商品详情",example = "无敌好产品", required = true)
    private String description;
    @ApiModelProperty(value = "商品规格", example = "xxxx", required = true)
    private String GoodsSpecFormat;
    @ApiModelProperty(value = "商品简介，促销语",example = "双11·促销节", required = true)
    private String introduction;
    @ApiModelProperty(value = "市场价格", example = "188.00", required = true)
    private BigDecimal marketPrice;
    @ApiModelProperty(value = "销售价格", example = "201.00", required = true)
    private BigDecimal salePrice;
    @ApiModelProperty(value = "成本价格", example = "101.00", required = true)
    private BigDecimal costPrice;
    @ApiModelProperty(value = "商品库存", example = "100", required = true)
    private Integer goodsCounts;
    @ApiModelProperty(value = "商品排序", example = "1", required = true)
    private Integer sort;
    @ApiModelProperty(value = "商品状态 0下架，1正常，10违规（禁售）", example = "1", required = true)
    private Integer state;
    @ApiModelProperty(value = "获取商品详细内容",example = "这是一款无敌产品",required = true)
    private String content;
}
