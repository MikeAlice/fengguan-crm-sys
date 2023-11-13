package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author 骇客老薛
 * @date 2023/10/27 16:00
 * com.zeroone.star.project.dto.j4.commodity
 */

@Data
@ApiModel("商品和状态传输对象")
public class RecommendDTO {
    @ApiModelProperty(value = "商品ID列表", example = "[1]", required = true)
    private List<Integer> goodsIdList;

    @ApiModelProperty(value = "是否推荐0=不推荐，1=推荐", example = "1", required = true)
    private Integer isRecommend;



}
