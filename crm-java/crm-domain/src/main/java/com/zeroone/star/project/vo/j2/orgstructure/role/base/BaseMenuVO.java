package com.zeroone.star.project.vo.j2.orgstructure.role.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * <p>
 * 系统菜单栏目
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Data
@ApiModel(value = "菜单权限表")
public class BaseMenuVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "菜单权限ID")
    private Integer id;

    @ApiModelProperty(value = "权限名称")
    private String name;

    @ApiModelProperty(value = "权限英文名称")
    private String nameEn;

    @ApiModelProperty(value = "权限图标路径")
    private String url;

    @ApiModelProperty(value = "父级ID")
    private Integer parentID;

    @ApiModelProperty(value = "排序")
    private Integer sort;

    @ApiModelProperty(value = "是否启用 (1启用，2停用)")
    private Integer visible;

}
