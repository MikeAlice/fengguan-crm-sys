package com.zeroone.star.project.query.j4.commodity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.math.BigDecimal;

/**
 * @author zhairenhao
 * @date 2023/10/22 21:37
 * @description 查询商品清单条件对象
 */
@Data
@ApiModel("查询商品清单条件对象")
public class GoodsSkuQuery extends PageQuery {

    @ApiModelProperty(value = "商品名称", example = "手机", required = false)
    private String goodsName;
}
