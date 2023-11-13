package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * @TableName fly_sys_role
 */
@TableName(value ="fly_sys_role")
@Data
public class FlySysRole implements Serializable {
    private Integer id;

    private Integer sort;

    private Integer visible;

    private Integer parentid;

    private String name;

    private String intro;

    private static final long serialVersionUID = 1L;
}