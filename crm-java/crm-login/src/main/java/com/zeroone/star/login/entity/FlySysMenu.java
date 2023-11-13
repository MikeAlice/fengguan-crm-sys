package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * @TableName fly_sys_menu
 */
@TableName(value ="fly_sys_menu")
@Data
public class FlySysMenu implements Serializable {
    private Integer id;

    private String name;

    private String nameEn;

    private String url;

    private Integer parentid;

    private Integer sort;

    private Integer visible;

    private String icon;

    private static final long serialVersionUID = 1L;
}