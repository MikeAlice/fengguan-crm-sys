package com.zeroone.star.project.query.j4.commodity;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.util.List;

/**
 * 查询品牌数据的条件对象数据
 */

@Data
@ApiModel("查询品牌数据的条件对象数据")
public class BrandQuery extends PageQuery {
    @ApiModelProperty(value = "品牌名称", example = "小米")
    private String brandName;

    @ApiModelProperty(value = "品牌首字母", example = "X")
    private String brandInitial;


}
