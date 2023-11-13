package com.zeroone.star.project.dto.j1.systemindex;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("商机统计上传数据，根据前端上传的数据，将信息进行三段展示")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class BusinessStatisticsDTO {

    @ApiModelProperty(value = "统计的第一个销售金额或成功率，通过该值统计小于该值的商机数量",example = "20",required = true)
    private Double firstData;

    @ApiModelProperty(value = "统计的第二个销售金额或成功率，通过该值统计大于该值和两值中间的商机数量",example = "50",required = true)
    private Double secondData;

}
