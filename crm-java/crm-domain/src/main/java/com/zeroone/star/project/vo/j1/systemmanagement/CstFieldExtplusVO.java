package com.zeroone.star.project.vo.j1.systemmanagement;

import io.swagger.annotations.ApiModelProperty;

import java.util.Date;

public class CstFieldExtplusVO {

    @ApiModelProperty(value ="字段数据类型" ,example ="varchar" )
    private String fieldType;

    public CstFieldExtplusVO(String fieldType){
        this.fieldType=fieldType;
    }

    public String getFieldType() {
        return fieldType;
    }

    public void setFieldType(String fieldType) {
        this.fieldType = fieldType;
    }
}
