package com.zeroone.star.project.vo.j1.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 权限列表vo模型
 *
 * @author 汐
 * @since 2023/11/1
 */
@Data
@ApiModel(value = "权限列表vo模型")
public class MethodListVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "权限ID")
    private Integer id;
    @ApiModelProperty(value = "菜单ID")
    private Integer menuID;
    @ApiModelProperty(value = "权限名称")
    private String name;
    @ApiModelProperty(value = "权限参数")
    private String value;
    @ApiModelProperty(value = "排序")
    private Integer sort;
    @ApiModelProperty(value = "启用状态：0=启用；1=禁用")
    private Integer visible;
}
