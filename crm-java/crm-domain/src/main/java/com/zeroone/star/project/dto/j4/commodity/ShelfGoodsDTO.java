package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import java.util.List;

/**
 * @author 骇客老薛
 * @date 2023/10/28 20:53
 * com.zeroone.star.project.dto.j4.commodity
 */
@Data
@ApiModel("修改商品售卖状态DTO")
public class ShelfGoodsDTO {

    @ApiModelProperty(value = "商品id列表", example = "[1]", required = true)
    private List<Integer> goodsIdList;

    @ApiModelProperty(value = "商品状态 0下架，1正常，10违规（禁售）", example = "1", required = true)
    private Integer state;
}
