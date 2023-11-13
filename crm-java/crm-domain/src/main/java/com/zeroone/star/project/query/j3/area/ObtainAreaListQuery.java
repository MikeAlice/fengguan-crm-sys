package com.zeroone.star.project.query.j3.area;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;

@Data
@ApiModel("获取区域列表")
public class ObtainAreaListQuery extends PageQuery {

    @ApiModelProperty(value = "查询条件", example = "四川（默认查询全部）",required = false)
    private String queryCondition;

    @ApiModelProperty(value = "父级id", example = "0",required = false)
    @Min(value = 1,message = "父级id最小值为1")
    private String pid;

}