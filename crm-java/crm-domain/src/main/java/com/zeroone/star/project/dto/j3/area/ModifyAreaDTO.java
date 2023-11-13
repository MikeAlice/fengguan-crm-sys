package com.zeroone.star.project.dto.j3.area;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("修改地区传输对象")
public class ModifyAreaDTO {

    @ApiModelProperty(value = "地区id", example = "1",required = true)
    private Integer id;
    @ApiModelProperty(value = "地区名", example = "西南地区")
    private String name;
    @ApiModelProperty(value = "父级地区id", example = "1")
    private Integer parentId;
    @ApiModelProperty(value = "排序号", example = "1")
    private Integer sort;
    @ApiModelProperty(value = "是否使用", example = "1")
    private Integer visible;
    @ApiModelProperty(value = "介绍", example = "xxxx")
    private String intro;
}
