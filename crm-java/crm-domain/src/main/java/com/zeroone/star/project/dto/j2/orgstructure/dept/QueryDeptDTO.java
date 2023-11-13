package com.zeroone.star.project.dto.j2.orgstructure.dept;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * 部门分页查询请求体参数
 * @author 叔
 * @date 2023/10/20 17:30
 */
@Data
@ApiModel(value = "部门分页查询请求体参数")
public class QueryDeptDTO {
    @ApiModelProperty(value = "id")
    private Integer id;
    @ApiModelProperty(value = "父级id")
    private Integer parentID;
    @ApiModelProperty(value = "部门名称",example = "零起飞工作室")
    private String name;
    @ApiModelProperty(value = "部门描述")
    private String intro;
    @ApiModelProperty(value = "排序",example = "10")
    private int sort;
    @ApiModelProperty(value = "是否启用：1=启用；2=禁用",example = "1")
    private int visible;
    @ApiModelProperty(value = "部门电话")
    private String tel;
    @ApiModelProperty(value = "部门传真")
    private String fax;
}
