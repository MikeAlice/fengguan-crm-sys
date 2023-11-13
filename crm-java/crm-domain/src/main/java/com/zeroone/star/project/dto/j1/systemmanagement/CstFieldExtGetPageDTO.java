package com.zeroone.star.project.dto.j1.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

public class CstFieldExtGetPageDTO {
    @ApiModel("获取指定扩展表单列表(分页+条件)")
    @Data
    @AllArgsConstructor
    @NoArgsConstructor
    public class CstFieldExtGetDTO {

        @ApiModelProperty(value = "编号", example = "1")
        private String fieldExtId;

        @ApiModelProperty(value = "关联主表", example = "cst_customer")
        private String mainTable;

        @ApiModelProperty(value = "扩展表名", example = "cst_customer",required = true)
        private String extTable;

        @ApiModelProperty(value = "字段表单名称", example = "客户代表")
        private String showName;

        @ApiModelProperty(value = "字段名称", example = "linkman")
        private String fieldName;

        @ApiModelProperty(value = "文本类型", example = "varchar")
        private String  fieldType;

        @ApiModelProperty(value = "字段默认值", example = "0")
        private Integer defaultValue;

        @ApiModelProperty(value = "最大值", example = "250")
        private Integer maxLength;

        @ApiModelProperty(value = "表单说明", example = "1 ")
        private String  desc;

        @ApiModelProperty(value = "是否使用", example = "1")
        private Integer visible;

        @ApiModelProperty(value = "是否为系统字段", example = "1")
        private Integer isSystem;

        @ApiModelProperty(value = "是否改填", example = "1")
        private Integer isMust;

        @ApiModelProperty(value = "显示排序", example = "0")
        private Integer sort;

        @ApiModelProperty(value = "创建时间", example = "2019-05-28 12:15:19")
        @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss", iso = DateTimeFormat.ISO.DATE_TIME)
        private LocalDateTime createTime;

        @ApiModelProperty(value = "创建用户id", example = "1")
        private Integer createUserId;
}}
