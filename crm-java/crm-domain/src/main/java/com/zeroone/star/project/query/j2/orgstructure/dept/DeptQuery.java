package com.zeroone.star.project.query.j2.orgstructure.dept;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.Min;

/**
 * @author 叔
 * @date 2023/10/20 17:56
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("部门查询对象")
public class DeptQuery extends PageQuery {

    @ApiModelProperty(value = "部门关键词", example = "技术部")
    private String keywords;
    @ApiModelProperty(value = "父级id", example = "0")
    @Min(value = 1, message = "父级id最小值为1")
    private Integer pid;
}
