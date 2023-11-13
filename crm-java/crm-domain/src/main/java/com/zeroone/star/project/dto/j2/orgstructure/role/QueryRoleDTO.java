package com.zeroone.star.project.dto.j2.orgstructure.role;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 角色分页查询请求体参数
 * @author 叔
 * @date 2023/10/20 17:52
 */
@Data
@ApiModel(value = "角色分页查询请求体参数")
public class QueryRoleDTO {
    @ApiModelProperty(value = "id")
    private Integer id;
    @ApiModelProperty(value = "父级id")
    private Integer parentID;
    @ApiModelProperty(value = "角色名称",example = "超级管理员")
    private String name;
    @ApiModelProperty(value = "角色描述")
    private String intro;
    @ApiModelProperty(value = "排序",example = "10")
    private int sort;
    @ApiModelProperty(value = "是否启用：1=启用；2=禁用",example = "1")
    private int visible;
}
