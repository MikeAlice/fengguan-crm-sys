package com.zeroone.star.project.vo.j4.commodity;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;
/**
 * 查询商品简单类型VO
 * @author Ak5ma1
 */
@Data
public class SimpleTypeVO {
    @ApiModelProperty(value = "类型名称",example = "硬盘")
    private String attrName;
    @ApiModelProperty(value = "启用",example = "true")
    private boolean visible;
    @ApiModelProperty(value = "排序",example = "1")
    private int sort;
    @ApiModelProperty(value="类型名称ID",example = "1")
    private int attrId;
    @ApiModelProperty(value = "属性标签",example = "大小")
    private List<String> attrValueName;

    public String getAttrName() {
        return attrName;
    }

    public void setAttrName(String attrName) {
        this.attrName = attrName;
    }

    public boolean isVisible() {
        return visible;
    }

    public void setVisible(boolean visible) {
        this.visible = visible;
    }

    public int getSort() {
        return sort;
    }

    public void setSort(int sort) {
        this.sort = sort;
    }

    public int getAttrId() {
        return attrId;
    }

    public void setAttrId(int attrId) {
        this.attrId = attrId;
    }

    public List<String> getAttrValueName() {
        return attrValueName;
    }

    public void setAttrValueName(List<String> attrValueName) {
        this.attrValueName = attrValueName;
    }
}
