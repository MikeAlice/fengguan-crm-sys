package com.zeroone.star.project.vo.j2.orgstructure.role.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * <p>
 * 角色表
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Data
@ApiModel(value = "角色表")
public class BaseRoleVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "角色ID")
    private Integer id;

    @ApiModelProperty(value = "排序")
    private Integer sort;

    @ApiModelProperty(value = "是否启用 (1启用，2禁用)")
    private Integer visible;

    @ApiModelProperty(value = "父级ID，一级为0")
    private Integer parentID;

    @ApiModelProperty(value = "角色名称")
    private String name;

    @ApiModelProperty(value = "角色介绍")
    private String intro;

}
