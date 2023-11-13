package com.zeroone.star.project.vo.j2.orgstructure.position.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * <p>
 * 职位表
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Data
@ApiModel(value = "岗位表")
public class BasePositionVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "岗位ID")
    private Integer id;

    @ApiModelProperty(value = "岗位名称")
    private String name;

    @ApiModelProperty(value = "父级ID，一级为0")
    private Integer parentID;

    @ApiModelProperty(value = "排序")
    private Integer sort;

    @ApiModelProperty(value = "是否启用 (1启用，2禁用)")
    private Integer visible;

    @ApiModelProperty(value = "岗位介绍")
    private String intro;

}
