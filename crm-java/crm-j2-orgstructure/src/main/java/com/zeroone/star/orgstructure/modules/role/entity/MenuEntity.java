package com.zeroone.star.orgstructure.modules.role.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 系统菜单栏目
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Getter
@Setter
@TableName("fly_sys_menu")
public class MenuEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String name;

    private String nameEn;

    private String url;

    @TableField("parentID")
    private Integer parentID;

    private Integer sort;

    private Integer visible;


}
