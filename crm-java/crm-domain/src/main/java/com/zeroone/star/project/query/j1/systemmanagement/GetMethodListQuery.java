package com.zeroone.star.project.query.j1.systemmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * 获取权限列表查询参数
 *
 * @author 汐
 * @since 2023/11/1
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "获取权限列表查询参数")
public class GetMethodListQuery extends PageQuery {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "菜单ID，0则查询所有权限列表 (默认为0)")
    private Integer menuId = 0;
    @ApiModelProperty(value = "权限名称")
    private String keywords;
}
