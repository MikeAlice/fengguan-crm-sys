package com.zeroone.star.project.dto.j1.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("权限管理传输对象")
@Data
public class FlySysMethodDTO {
    @ApiModelProperty(value = "编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "菜单id",example = "0")
    private Integer menuID;

    @ApiModelProperty(value = "权限名称",example = "消息服务")
    private String name;

    @ApiModelProperty(value = "权限值",example = "message_service")
    private String value;

    @ApiModelProperty(value = "显示顺序",example = "1")
    private Integer sort;

    @ApiModelProperty(value = "是否显示",example = "0")
    private Integer visible;
}
