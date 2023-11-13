package com.zeroone.star.project.dto.j2.orgstructure.position;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.io.Serializable;

/**
 * 新增岗位DTO
 *
 * @author 汐
 * @since 2023/10/25
 */
@Data
@ApiModel(value = "新增岗位DTO")
public class AddPositionDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotBlank(message = "岗位名称不能为空")
    @ApiModelProperty(value = "名称", required = true, example = "总经理")
    private String name;

    @ApiModelProperty(value = "父级ID (默认一级为0)", example = "1")
    private Integer parentID;

    @ApiModelProperty(value = "排序 (默认为0)", example = "0")
    private Integer sort;

    @Min(value = 1, message = "启用值范围为1-2")
    @Max(value = 2, message = "启用值范围为1-2")
    @ApiModelProperty(value = "是否启用：1->启用；2->禁用 (默认为2禁用)", example = "1")
    private Integer visible;

    @ApiModelProperty(value = "介绍", example = "管理员工")
    private String intro;
}
