package com.zeroone.star.project.query.j2.orgstructure.dept;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * Author：Larry
 * Date：2023/10/20 21:26
 * 一天代码十万三
 */
@Data
@ApiModel("部门查询对象")
public class DeptTreeQuery {

    @ApiModelProperty(value = "部门关键词", example = "技术部")
    private String keywords;
    @ApiModelProperty(value = "id", example = "1")
    private Integer id;

}
