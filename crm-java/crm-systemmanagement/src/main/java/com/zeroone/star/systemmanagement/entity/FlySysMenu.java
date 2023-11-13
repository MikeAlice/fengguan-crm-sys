package com.zeroone.star.systemmanagement.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

import lombok.*;

/**
 * <p>
 * 系统菜单栏目
 * </p>
 *
 * @author dzcgood
 * @since 2023-10-20
 */
@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
@TableName("fly_sys_menu")
public class FlySysMenu implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String name;

    private String nameEn;

    private String url;

    @TableField(value = "parentID")
    private Integer parentID;

    private Integer sort;

    private Integer visible;


}
