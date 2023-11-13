package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;

/**
 * 修改商品类型DTO
 * @author Ak5ma1
 */
@Getter
@Data
@ApiModel("详细类型信息")
public class DetailedTypeInfoDTO {

    public void setAttrValueName(String attrValueName) {
        this.attrValueName = attrValueName;
    }

    public void setVisible(boolean visible) {
        this.visible = visible;
    }

    public void setSort(int sort) {
        this.sort = sort;
    }

    public void setSearch(int search) {
        this.search = search;
    }

    public void setAttrValueData(String attrValueData) {
        this.attrValueData = attrValueData;
    }

    public void setAttrId(int attrId) {
        this.attrId = attrId;
    }

    public void setAttrValueId(int attrValueId) {
        this.attrValueId = attrValueId;
    }

    public void setType(Integer type) {
        this.type = type;
    }

    //    @ApiModelProperty(value = "类型名称",example = "硬盘")
//    private String attrName;
    @ApiModelProperty(value = "属性标签",example = "大小")
    private String attrValueName;
    @ApiModelProperty(value = "启用",example = "true")
    private boolean visible;
    @ApiModelProperty(value = "排序",example = "1")
    private int sort;
    @ApiModelProperty(value = "是否筛选",example = "1")
    private int search;
    @ApiModelProperty(value = "属性值",example = "2U设备")
    private String attrValueData;
    @ApiModelProperty(value="类型名称ID",example = "1")
    private int attrId;
    @ApiModelProperty(value="属性值ID",example = "1")
    private int attrValueId;
    @ApiModelProperty(value="属性对应输入类型1.直接2.单选3.多选",example = "2")
    private Integer type;

    @Override
    public String toString() {
        return "DetailedTypeInfoDTO{" +
                "attrValueName='" + attrValueName + '\'' +
                ", visible=" + visible +
                ", sort=" + sort +
                ", search=" + search +
                ", attrValueData='" + attrValueData + '\'' +
                ", attrId=" + attrId +
                ", attrValueId=" + attrValueId +
                ", type=" + type +
                '}';
    }
}
