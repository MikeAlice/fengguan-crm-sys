package com.zeroone.star.project.vo.j1.systemindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("商机统计信息显示结果")
@Data
public class BusinessStatisticsVO {
    @ApiModelProperty(value = "统计的字段分类名或范围名,若统计总数量则该值为空",example = "成功率小于30%")
    String statisticsName;
    @ApiModelProperty(value = "统计字段对应的商机数量",example = "10",required = true)
    Integer statisticsNumber;
}
