package com.zeroone.star.project.vo.j3.area;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * @Description: 获取区域列表数据
 * @Author: your name
 * @Date: 2023/10/31 20:01
 */
@Data
@ApiModel("获取区域列表数据VO")
@AllArgsConstructor
public class AreaListVO {

    @ApiModelProperty(value = "区域id，唯一标识",example ="1",required = true)
    private Integer id;

    @ApiModelProperty(value = "区域名称",example = "华南",required = true)
    private String name;
}
