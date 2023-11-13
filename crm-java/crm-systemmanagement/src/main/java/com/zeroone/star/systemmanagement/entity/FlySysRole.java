package com.zeroone.star.systemmanagement.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 权限列表
 * </p>
 *
 * @author starman
 * @since 2023-10-22
 */
@Getter
@Setter
@TableName("fly_sys_role")
public class FlySysRole implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private Integer sort;

    private Integer visible;

    private Integer parentID;

    private String name;

    private String intro;


}
