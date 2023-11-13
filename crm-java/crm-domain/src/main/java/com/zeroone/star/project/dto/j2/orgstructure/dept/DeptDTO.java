package com.zeroone.star.project.dto.j2.orgstructure.dept;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：部门数据传输对象
 * </p>
 *
 * @author 望三星
 * @version 1.0.0
 * @date 2023/10/21
 */
@Data
@ApiModel("部门数据传输对象")
public class DeptDTO {
    @ApiModelProperty(value = "部门ID", example = "1")
    private Integer id;

    @ApiModelProperty(value = "部门名称", example = "研发部")
    private String name;

    @ApiModelProperty(value = "父级ID，一级为0")
    private Integer parentID;

    @ApiModelProperty(value = "排序")
    private Integer sort;

    @ApiModelProperty(value = "是否启用 (1启用，2禁用)")
    private Integer visible;

    @ApiModelProperty(value = "部门电话", example = "12345678901")
    private String tel;

    @ApiModelProperty(value = "部门传真号", example = "26737123")
    private String fax;

    @ApiModelProperty(value = "部门介绍")
    private String intro;
}
