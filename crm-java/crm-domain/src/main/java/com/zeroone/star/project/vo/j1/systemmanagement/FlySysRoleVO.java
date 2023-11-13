package com.zeroone.star.project.vo.j1.systemmanagement;

import io.swagger.annotations.ApiModelProperty;

public class FlySysRoleVO {
    @ApiModelProperty(value = "编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "分类",example = "1")
    private Integer sort;

    @ApiModelProperty(value = "可见性",example = "1")
    private Integer visible;

    @ApiModelProperty(value = "父类id",example = "1")
    private Integer parentID;

    @ApiModelProperty(value = "名称",example = "权限名")
    private String name;

    @ApiModelProperty(value = "权限介绍",example = "最高管理权限")
    private String intro;
}
