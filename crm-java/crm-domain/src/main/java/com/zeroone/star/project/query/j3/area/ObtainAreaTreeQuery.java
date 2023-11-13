package com.zeroone.star.project.query.j3.area;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("获取区域名称结构树")
public class ObtainAreaTreeQuery {
    @ApiModelProperty(value = "父ID,一级为0(默认为0)", example = "1")
    private Integer pid = 0;
    @ApiModelProperty(value = "查询深度，0为查询所有(默认为0)", example = "1")
    private Integer depth = 0;
}
