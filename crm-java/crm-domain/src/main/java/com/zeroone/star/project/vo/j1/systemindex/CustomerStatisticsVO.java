package com.zeroone.star.project.vo.j1.systemindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("客户统计信息显示结果")
@Data
public class CustomerStatisticsVO {
    @ApiModelProperty(value = "统计的字段分类名,若统计总数量则该值为空",example = "互联网行业")
    String statisticsName;
    @ApiModelProperty(value = "统计字段对应的客户数量",example = "10")
    Integer statisticsNumber;
}
