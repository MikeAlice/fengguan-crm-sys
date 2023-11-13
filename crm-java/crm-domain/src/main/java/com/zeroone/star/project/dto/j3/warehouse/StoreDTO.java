package com.zeroone.star.project.dto.j3.warehouse;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @Description: 用于查看所有列表数据和导出
 * @Author: 4.5
 * @Date: 2023/10/22 15:00
 */
@Data
@ApiModel("仓库表DTO模型")
public class StoreDTO {

    @ApiModelProperty(value = "id唯一标识", example = "1", required = true)
    private Integer storeId;

    @ApiModelProperty(value = "名字", example = "辣条仓库", required = true)
    private String name;

    @ApiModelProperty(value = "创建人id", example = "2", required = true)
    private Integer createUserId;

    @ApiModelProperty(value = "排序", example = "5", required = true)
    private Integer sort;

    @ApiModelProperty(value = "是否启用", example = "是", required = true)
    private Integer visible;

    @ApiModelProperty(value = "创建时间", example = "2023-10-11 21:36:34", required = true)
    private Date createTime;
}

