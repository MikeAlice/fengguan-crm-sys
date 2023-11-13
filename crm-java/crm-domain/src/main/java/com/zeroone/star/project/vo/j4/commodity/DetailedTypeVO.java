package com.zeroone.star.project.vo.j4.commodity;

import com.zeroone.star.project.dto.j4.commodity.DetailedTypeInfoDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import java.io.Serializable;
import java.util.List;
/**
 * 查询详细信息VO
 * @author Ak5ma1
 */
@Getter
@Data
@Setter
public class DetailedTypeVO implements Serializable {
    @Override
    public String toString() {
        return "DetailedTypeVO{" +
                "attrName='" + attrName + '\'' +
                ", visible=" + visible +
                ", sort=" + sort +
                ", attrId=" + attrId +
                ", detailedTypeInfoDTOList=" + detailedTypeInfoDTOList +
                '}';
    }

    @NotNull(message = "类型名称不能为空")
    @ApiModelProperty(value = "类型名称",example = "硬盘")
    private String attrName;
    @NotNull(message = "是否可见不能为空")
    @ApiModelProperty(value = "启用",example = "true")
    private boolean visible;
    @Min(value = 0,message = "排序不能小于0")
    @ApiModelProperty(value = "排序",example = "1")
    private int sort;
    @Min(value = 1,message = "类型名称ID最小为1")
    @ApiModelProperty(value="类型名称ID",example = "1")
    private int attrId;
    @ApiModelProperty(value="类型标签，不可用于新增")
    List<DetailedTypeInfoDTO> detailedTypeInfoDTOList;

    public void setAttrName(String attrName) {
        this.attrName = attrName;
    }

    public void setVisible(boolean visible) {
        this.visible = visible;
    }

    public void setSort(int sort) {
        this.sort = sort;
    }

    public void setAttrId(int attrId) {
        this.attrId = attrId;
    }

    public void setDetailedTypeInfoDTOList(List<DetailedTypeInfoDTO> detailedTypeInfoDTOList) {
        this.detailedTypeInfoDTOList = detailedTypeInfoDTOList;
    }
}
