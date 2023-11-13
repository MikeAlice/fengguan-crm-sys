package com.zeroone.star.project.vo.j1.systemmanagement;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;

@Data
@EqualsAndHashCode
public class MenuVO implements Serializable {

    @ApiModelProperty(value = "id", example = "22")
    private Integer id;

    @ApiModelProperty(value = "父菜单id", example = "1")
    private Integer parentId;

    @ApiModelProperty(value = "图标", example = "http://localhost:6666/a.png")
    private String icon;

    @ApiModelProperty(value = "名称", example = "系统管理")
    private String name;

    @ApiModelProperty(value = "英文名称", example = "system management")
    private String nameEn;

    @ApiModelProperty(value = "目标url", example = "/home/index.html")
    private String url;

    @ApiModelProperty(value = "菜单排序值", example = "16")
    private Integer sort;

    @ApiModelProperty(value = "菜单是否可见（0：不可见， 1：可见）", example = "1")
    private Integer visible;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
