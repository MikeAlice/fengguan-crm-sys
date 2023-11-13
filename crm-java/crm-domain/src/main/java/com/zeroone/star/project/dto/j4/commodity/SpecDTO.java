package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 *      描述： 商品规格的传输数据对象
 * </p>
 *
 *   @author Tezz
 *   @version 1.0.0
 */

@Data
@ApiModel("商品规格的传输数据对象")
public class SpecDTO {
    @NotBlank(message = "规格名称不能为空")
    @ApiModelProperty(value = "规格名称",example = "尺码")
    private  String  specName;

//    @NotBlank(message = "规格排序不能为空")
    @ApiModelProperty(value = "规格排序",example = "1")
    private Integer specId;


    @ApiModelProperty(value = "是否启用",example = "true")
    private Boolean visible;

    @ApiModelProperty(value = "规格值排序",example = "1")
    private Integer sort;

    @NotBlank(message = "规格值不能为空")
    @ApiModelProperty(value = "规格值",example = "42码")
    private String specDes;







}
