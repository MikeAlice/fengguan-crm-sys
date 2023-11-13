package com.zeroone.star.systemmanagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 客户字段扩展表
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@Getter
@Setter
@TableName("cst_field_ext")
public class CstFieldExt implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "field_ext_id", type = IdType.AUTO)
    private Integer fieldExtId;

    /**
     * 关联主表
     */
    private String mainTable;

    /**
     * 扩展表名
     */
    private String extTable;

    /**
     * 字段表单名称
     */
    private String showName;

    /**
     * 字段名称
     */
    private String fieldName;

    /**
     * 单文本=varchar,文本=text,多行文本=textarea,整数=int,小数=float,图片=img,下拉=option,单选=radio,复选=checkbox
     */
    private String fieldType;

    /**
     * 字段默认值
     */
    private String defaultValue;

    /**
     * 最大值
     */
    private String maxlength;

    /**
     * 表单说明
     */
    @TableField("`desc`")
    private String desc;

    /**
     * 是否使用
     */
    private Integer visible;

    /**
     * 是否为系统字段，1=是（不能删除）0=否
     */
    private Integer isSystem;

    /**
     * 是否改填
     */
    private Integer isMust;

    /**
     * 显示排序
     */
    private Integer sort;

    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    private Integer createUserId;


}
