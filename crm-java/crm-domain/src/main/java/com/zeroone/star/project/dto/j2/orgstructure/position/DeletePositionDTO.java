package com.zeroone.star.project.dto.j2.orgstructure.position;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;
import java.io.Serializable;

/**
 * 删除岗位DTO
 *
 * @author 汐
 * @since 2023/10/25
 */
@Data
@ApiModel(value = "删除岗位DTO")
public class DeletePositionDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotNull(message = "岗位ID不能为空")
    @ApiModelProperty(value = "岗位ID", required = true, example = "1")
    private Integer positionId;
}
