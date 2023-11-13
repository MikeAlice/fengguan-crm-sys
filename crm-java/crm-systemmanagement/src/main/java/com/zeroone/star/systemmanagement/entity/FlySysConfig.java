package com.zeroone.star.systemmanagement.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

import lombok.Data;

/**
 * <p>
 * 系统配置表
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@Data
@TableName("fly_sys_config")
public class FlySysConfig implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String name;

    private String varname;

    private String value;

    /**
     * 字段类型
     */
    private String type;

    private Integer groupid;


}
