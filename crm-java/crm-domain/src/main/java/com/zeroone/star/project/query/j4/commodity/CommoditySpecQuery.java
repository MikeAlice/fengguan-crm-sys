package com.zeroone.star.project.query.j4.commodity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * @author zhairenhao
 * @date 2023/10/22 21:44
 * @description 查询商品规格条件对象
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("获取商品规格列表")
public class CommoditySpecQuery extends PageQuery {
    @NotBlank(message = "规格名称不能为空")
    @ApiModelProperty(value = "规格名称",example = "尺码",required = true)
    private  String  specName;
//    @NotBlank(message = "规格排序不能为空")
//    @ApiModelProperty(value = "规格排序",example = "1")
//    private Integer specId;

//    @ApiModelProperty(value = "是否启用",example = "true")
//    private Boolean visible;

//    @ApiModelProperty(value = "规格值排序",example = "1")
//    private Integer sort;

    @NotBlank(message = "规格值不能为空")
    @ApiModelProperty(value = "规格值",example = "42码")
    private String specDes;

}
