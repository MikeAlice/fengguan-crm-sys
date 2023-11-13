package com.zeroone.star.project.query.j4.commodity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author zhairenhao
 * @date 2023/10/22 22:47
 * @description 查询商品条件对象
 */
@Data
@ApiModel("查询商品条件对象")
public class GoodsQuery extends PageQuery {
    @ApiModelProperty(value = "商品名称", example = "手机", required = false)
    private String goodsName;
}
