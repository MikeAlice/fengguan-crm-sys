package com.zeroone.star.area.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * @Description: 地区
 * @Author: your name
 * @Date: 2023/10/24 17:34
 */
@Data
@TableName("fly_sys_area")
public class Area {

    @TableId(type = IdType.AUTO)
    private Integer id;

    @TableField("parentID")
    private Integer parentID;

    private Integer sort;

    private String name;

    private Integer type;

    private Integer visible;

    private String intro;
}
