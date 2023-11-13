package com.zeroone.star.project.dto.j1.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("系统参数传输对象")
@Data
public class FlySysConfigDTO {
    @ApiModelProperty(value = "编号", example = "1" )
    private Integer id;

    @ApiModelProperty(value = "名称", example = "系统根网址： " )
    private String name;

    @ApiModelProperty(value = "英文名称", example = "cfg_basehost" )
    private String varname;

    @ApiModelProperty(value = "对应数据", example = "http://www.zostar.com" )
    private String value;

    @ApiModelProperty(value = "字段类型", example = "string" )
    private String type;

    @ApiModelProperty(value = "分组id", example = "0" )
    private Integer groupid;
}
