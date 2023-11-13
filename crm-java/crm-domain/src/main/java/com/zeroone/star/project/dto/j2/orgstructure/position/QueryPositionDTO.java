package com.zeroone.star.project.dto.j2.orgstructure.position;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 岗位分页查询请求体参数
 * @author 叔
 * @date 2023/10/20 17:47
 */
@Data
@ApiModel(value = "岗位分页查询请求体参数")
public class QueryPositionDTO {
    @ApiModelProperty(value = "id")
    private Integer id;
    @ApiModelProperty(value = "父级id")
    private Integer parentID;
    @ApiModelProperty(value = "职务名称",example = "总经理")
    private String name;
    @ApiModelProperty(value = "职务描述")
    private String intro;
    @ApiModelProperty(value = "排序",example = "10")
    private int sort;
    @ApiModelProperty(value = "是否启用：1=启用；2=禁用",example = "1")
    private int visible;
}
