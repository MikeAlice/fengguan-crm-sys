package com.zeroone.star.project.dto.j2.orgstructure.role;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel("新增角色请求体")
public class AddRoleDTO implements Serializable {
    @ApiModelProperty("角色名称")
    private String name;
    @ApiModelProperty("父id")
    private Integer parentID;
    @ApiModelProperty("排序")
    private Integer sort;
    @ApiModelProperty("是否启用 1-启用，2-禁用")
    private Integer visible;
    @ApiModelProperty("简介")
    private String intro;
}
