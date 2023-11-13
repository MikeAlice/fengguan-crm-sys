package com.zeroone.star.project.query.j2.orgstructure.role;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.Min;

/**
 * @author 叔
 * @date 2023/10/20 17:58
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("角色查询对象")
public class RoleQuery extends PageQuery {
    @ApiModelProperty(value = "角色关键词", example = "超级管理员")
    private String keyword;
    @ApiModelProperty(value = "父级id", example = "0")
    @Min(value = 1, message = "父级id最小值为1")
    private Integer pid;
}
