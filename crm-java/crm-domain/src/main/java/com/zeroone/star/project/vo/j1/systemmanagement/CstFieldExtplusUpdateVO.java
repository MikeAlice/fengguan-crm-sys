package com.zeroone.star.project.vo.j1.systemmanagement;


import io.swagger.annotations.ApiModelProperty;


import java.time.LocalDateTime;


public class CstFieldExtplusUpdateVO {
    @ApiModelProperty(value ="字段id" ,example ="1" )
    private Integer fieldExtId;

    @ApiModelProperty(value ="关联主表" ,example ="test" )
    private String mainTable;

    @ApiModelProperty(value ="扩展表名" ,example ="test" )
    private String extTable;

    @ApiModelProperty(value ="字段表单名称",example ="客户信息表" )
    private String showName;

    @ApiModelProperty(value ="字段名称" ,example ="客户名称" )
    private String fieldName;

    @ApiModelProperty(value ="字段数据类型" ,example ="varchar" )
    private String fieldType;

    @ApiModelProperty(value ="字段默认值" ,example ="1" )
    private String defaultValue;

    @ApiModelProperty(value ="最大值" ,example ="255" )
    private String maxlength;

    @ApiModelProperty(value ="表单说明" ,example ="客户..." )
    private String desc;

    @ApiModelProperty(value ="是否使用" ,example ="1" )
    private Integer visible;

    @ApiModelProperty(value ="2表示添加后被禁用，0表示压根没添加，1表示启用。" ,example ="2" )
    private Integer isSystem;

    @ApiModelProperty(value ="是否改填" ,example ="0" )
    private Integer isMust;

    @ApiModelProperty(value ="显示排序" ,example ="0" )
    private Integer sort;

    @ApiModelProperty
    private LocalDateTime createTime;

    @ApiModelProperty
    private Integer createUserId;



    public Integer getFieldExtId() {
        return fieldExtId;
    }

    public void setFieldExtId(Integer fieldExtId) {
        this.fieldExtId = fieldExtId;
    }

    public String getMainTable() {
        return mainTable;
    }

    public void setMainTable(String mainTable) {
        this.mainTable = mainTable;
    }

    public String getExtTable() {
        return extTable;
    }

    public void setExtTable(String extTable) {
        this.extTable = extTable;
    }

    public String getShowName() {
        return showName;
    }

    public void setShowName(String showName) {
        this.showName = showName;
    }

    public String getFieldName() {
        return fieldName;
    }

    public void setFieldName(String fieldName) {
        this.fieldName = fieldName;
    }

    public String getFieldType() {
        return fieldType;
    }

    public void setFieldType(String fieldType) {
        this.fieldType = fieldType;
    }

    public String getDefaultValue() {
        return defaultValue;
    }

    public void setDefaultValue(String defaultValue) {
        this.defaultValue = defaultValue;
    }

    public String getMaxlength() {
        return maxlength;
    }

    public void setMaxlength(String maxlength) {
        this.maxlength = maxlength;
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public Integer getVisible() {
        return visible;
    }

    public void setVisible(Integer visible) {
        this.visible = visible;
    }

    public Integer getIsSystem() {
        return isSystem;
    }

    public void setIsSystem(Integer isSystem) {
        this.isSystem = isSystem;
    }

    public Integer getIsMust() {
        return isMust;
    }

    public void setIsMust(Integer isMust) {
        this.isMust = isMust;
    }

    public Integer getSort() {
        return sort;
    }

    public void setSort(Integer sort) {
        this.sort = sort;
    }

    public LocalDateTime getCreateTime() {
        return createTime;
    }

    public void setCreateTime(LocalDateTime createTime) {
        this.createTime = createTime;
    }

    public Integer getCreateUserId() {
        return createUserId;
    }

    public void setCreateUserId(Integer createUserId) {
        this.createUserId = createUserId;
    }
}
