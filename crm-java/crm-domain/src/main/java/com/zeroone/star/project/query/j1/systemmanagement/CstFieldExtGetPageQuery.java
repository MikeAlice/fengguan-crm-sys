package com.zeroone.star.project.query.j1.systemmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("获取指定表单扩展字段列表（分页+条件")
public class CstFieldExtGetPageQuery extends PageQuery {

    @ApiModelProperty(value = "当前页码")
    private Integer page; // 当前页码
    @ApiModelProperty(value = "每页记录数")
    private long pageSize; // 每页记录数


}
