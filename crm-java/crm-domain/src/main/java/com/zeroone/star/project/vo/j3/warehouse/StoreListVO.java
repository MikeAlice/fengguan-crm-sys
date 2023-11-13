package com.zeroone.star.project.vo.j3.warehouse;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;

/**
 * @Description: 获取仓库列表数据
 * @Author: your name
 * @Date: 2023/10/31 20:05
 */
@Data
@ApiModel("获取仓库列表数据")
@AllArgsConstructor
public class StoreListVO {

    @ApiModelProperty(value = "仓库id，唯一标识",example ="1",required = true)
    private Integer storeId;

    @ApiModelProperty(value = "仓库名称",example = "辣条仓库",required = true)
    private String name;
}
