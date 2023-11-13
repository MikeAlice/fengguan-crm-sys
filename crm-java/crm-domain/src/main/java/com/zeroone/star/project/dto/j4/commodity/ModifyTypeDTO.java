package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;

@Getter
@Setter
@ApiModel("页面详细信息，包括新增标签")
//extends DetailedTypeVO
public class ModifyTypeDTO  {

    public void setAttrValueIdsToDelete(int[] attrValueIdsToDelete) {
        this.attrValueIdsToDelete = attrValueIdsToDelete;
    }
//    @Min(value = -1)
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
    @Min(value = 1,message = "类型名称ID最小为1")
    @NotNull(message = "类型ID不能为空")
    @ApiModelProperty(value="类型名称ID",example = "1")
    private int attrId;
    @ApiModelProperty(value="类型标签，不可用于新增")
    List<DetailedTypeInfoDTO> detailedTypeInfoDTOList;
    @ApiModelProperty(value="要删除的属性id数组")
    private int[] attrValueIdsToDelete;
    @ApiModelProperty(value="要增加的属性标签")
    List<AddTypeDTO> detailedTypeToAddList;
}
