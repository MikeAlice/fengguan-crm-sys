package com.zeroone.star.project.query.j1.systemmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import lombok.Data;

@Data
@ApiModel("获取表单扩展字段列表")
public class CstFieldExtGetQuery extends PageQuery {

    private String mainTable;
    private String extTable;
    private Integer visible;
    private Integer isSystem;
    private Integer isMust;
    private int limit;
    private int offset;
}
