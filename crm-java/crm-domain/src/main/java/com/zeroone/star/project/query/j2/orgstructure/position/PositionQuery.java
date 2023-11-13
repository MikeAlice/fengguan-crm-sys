package com.zeroone.star.project.query.j2.orgstructure.position;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.QueryPositionDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.Min;

/**
 * @author 叔
 * @date 2023/10/20 17:57
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("岗位查询对象")
public class PositionQuery extends PageQuery {

    @ApiModelProperty(value = "岗位关键词", example = "总经理")
    private String keyword;
    @ApiModelProperty(value = "父级id", example = "0")
    @Min(value = 1, message = "父级id最小值为1")
    private Integer pid;

}
