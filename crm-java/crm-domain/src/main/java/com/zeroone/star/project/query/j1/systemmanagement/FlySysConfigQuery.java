package com.zeroone.star.project.query.j1.systemmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("系统参数查询对象")
public class FlySysConfigQuery extends PageQuery {
}
