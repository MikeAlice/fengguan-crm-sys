package com.zeroone.star.project.dto.j3.area;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel("地区分页查询请求体参数")
public class AreaInfoDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "地区id", example = "1",required = true)
    private Integer id;
    @ApiModelProperty(value = "地区名", example = "西南地区")
    private String name;
    @ApiModelProperty(value = "父级ID", example = "10",required = true)
    private Integer parentID;
    @ApiModelProperty(value = "排序号", example = "1")
    private Integer sort;
    @ApiModelProperty(value = "是否使用", example = "1")
    private Integer visible;
    @ApiModelProperty(value = "介绍", example = "xxxx")
    private String intro;
}
