package com.zeroone.star.project.dto.j3.area;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("删除地区传输对象")
public class DeleteAreaDTO {
    @ApiModelProperty(value = "地区id", example = "1",required = true)
    private Integer id;
}
