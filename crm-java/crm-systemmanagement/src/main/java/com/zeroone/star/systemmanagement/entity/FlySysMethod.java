package com.zeroone.star.systemmanagement.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 系统方法
 * </p>
 *
 * @author 点点
 * @since 2023-11-01
 */
@Getter
@Setter
@TableName("fly_sys_method")
public class FlySysMethod implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 菜单id
     */
    @TableField("menuID")

    private Integer menuID;

    private String name;

    private String value;

    private Integer sort;

    private Integer visible;


}
