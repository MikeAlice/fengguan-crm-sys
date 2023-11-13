package com.zeroone.star.project.vo.j2.orgstructure.role.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * <p>
 * 系统方法表
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Data
@ApiModel(value = "系统方法表")
public class BaseMethodVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "系统方法ID")
    private Integer id;

    @ApiModelProperty(value = "菜单权限ID")
    private Integer menuID;

    @ApiModelProperty(value = "系统方法名称")
    private String name;

    @ApiModelProperty(value = "系统方法值")
    private String value;

    @ApiModelProperty(value = "排序")
    private Integer sort;

    @ApiModelProperty(value = "是否启用 (1启用，2停用)")
    private Integer visible;

}
