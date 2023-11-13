package com.zeroone.star.project.dto.j3.area;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("新增地区传输对象")
public class InsertAreaDTO {
    @ApiModelProperty(value = "地区名", example = "西南地区",required = true)
    private String name;
    @ApiModelProperty(value = "父级地区id", example = "1",required = true)
    private Integer parentId;
    @ApiModelProperty(value = "排序号", example = "1",required = true)
    private Integer sort;
    @ApiModelProperty(value = "是否使用", example = "0",required = true,notes = "0为未启用，1为启用")
    private Integer visible;
    @ApiModelProperty(value = "介绍", example = "xxxx",required = true)
    private String intro;
}
