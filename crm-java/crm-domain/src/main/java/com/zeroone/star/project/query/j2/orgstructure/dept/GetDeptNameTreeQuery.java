package com.zeroone.star.project.query.j2.orgstructure.dept;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 获取部门名称结构树
 *
 * @author 汐
 * @since 2023/10/31
 */
@Data
@ApiModel(value = "获取部门名称结构树")
public class GetDeptNameTreeQuery implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "父级部门ID，一级为0 (默认为0)")
    private Integer pid = 0;
    @ApiModelProperty(value = "查询深度，为0查询所有 (默认为0)")
    private Integer depth = 0;
}
