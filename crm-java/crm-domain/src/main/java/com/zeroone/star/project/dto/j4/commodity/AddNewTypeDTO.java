package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;
@Data
@ApiModel("新增类型")
public class AddNewTypeDTO {
    @NotBlank(message = "类型名称不能为空")
    @ApiModelProperty(value = "类型名称",example = "硬盘")
    private String attrName;
    @NotNull(message = "是否可见不能为空")
    @ApiModelProperty(value = "启用",example = "true")
    private boolean visible;
    @Min(value = 0,message = "排序不能小于0")
    @NotNull(message = "排序不能为空")
    @ApiModelProperty(value = "排序",example = "1")
    private int sort;
    @NotNull(message = "类型ID不能为空")
    @ApiModelProperty(value="要增加的属性标签")
    List<AddTypeDTO> detailedTypeToAddList;
}
