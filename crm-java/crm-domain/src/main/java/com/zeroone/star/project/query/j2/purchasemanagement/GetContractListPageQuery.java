package com.zeroone.star.project.query.j2.purchasemanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：获取明细列表查询参数
 * </p>
 *
 * @author 望三星
 * @version 1.0.0
 * @date 2023/10/31
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "获取明细列表查询参数")
public class GetContractListPageQuery extends PageQuery {

    @ApiModelProperty(value = "商品名称关键字", example = "51685")
    private String goodsName;

    @ApiModelProperty(value = "SKU 名称关键字", example = "颜色:黑色,尺寸:40码")
    private String skuName;
}
