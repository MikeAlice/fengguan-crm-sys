
package com.zeroone.star.project.vo.j2.orgstructure.role.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * <p>
 * 角色菜单关联表
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Data
@ApiModel(value = "角色菜单关联表")
public class BaseRoleMenuVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "角色菜单关联ID")
    private Integer id;

    @ApiModelProperty(value = "角色ID")
    private Integer roleId;

    @ApiModelProperty(value = "菜单权限ID")
    private Integer menuId;

}
