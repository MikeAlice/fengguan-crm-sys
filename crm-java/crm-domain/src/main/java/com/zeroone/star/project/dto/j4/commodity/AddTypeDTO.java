package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@Getter
@Setter
public class AddTypeDTO {
    @NotBlank(message = "属性标签不能为空")
    @ApiModelProperty(value = "属性标签",example = "大小")
    private String attrValueName;
    @NotNull(message = "visible不能为空")
    @ApiModelProperty(value = "启用",example = "true")
    private boolean visible;
    @NotNull(message = "排序不能为空")
    @Min(value = 0,message = "排序不能小于0")
    @ApiModelProperty(value = "排序",example = "1")
    private int sort;
    @ApiModelProperty(value = "是否筛选",example = "1")
    private int search;
    @NotBlank(message = "属性值不能为空")
    @ApiModelProperty(value = "属性值",example = "2U设备")
    private String attrValueData;
    @NotNull(message = "类型名称ID不能为空")
    @ApiModelProperty(value="类型名称ID",example = "1")
    private int attrId;
    @NotNull(message = "属性对应输入类型不能为空")
    @ApiModelProperty(value="属性对应输入类型1.直接2.单选3.多选",example = "1")
    private Integer type;
}
