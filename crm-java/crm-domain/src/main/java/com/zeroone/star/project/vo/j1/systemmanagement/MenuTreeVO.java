package com.zeroone.star.project.vo.j1.systemmanagement;

import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonIgnore;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;


@Data
@EqualsAndHashCode
public class MenuTreeVO implements Serializable {

    @ApiModelProperty(value = "id", example = "22")
    private Integer id;

    @ApiModelProperty(value = "父菜单id", example = "1")
    @JsonIgnore
    private Integer parentId;

    @ApiModelProperty(value = "图标", example = "http://localhost:6666/a.png")
    private String icon;

    @ApiModelProperty(value = "名称", example = "系统管理")
    private String name;

    @ApiModelProperty(value = "英文名称", example = "system management")
    private String nameEn;

    @ApiModelProperty(value = "目标url", example = "http://localhost:6666/index.html")
    private String url;

    @ApiModelProperty(value = "菜单排序值", example = "16")
    @JsonIgnore
    private Integer sort;

    private List<MenuTreeVO> children;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    public void addChild(MenuTreeVO child) {

        if(Objects.isNull(children)) {
            children = new ArrayList<>();
        }

        children.add(child);

    }
}
