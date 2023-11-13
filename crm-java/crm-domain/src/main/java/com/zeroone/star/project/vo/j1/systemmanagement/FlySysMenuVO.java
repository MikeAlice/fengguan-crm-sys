package com.zeroone.star.project.vo.j1.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

/**
 * @author DzcGood
 * @date 2023/10/20 - 15:59
 */
@ApiModel("菜单显示对象")
@Builder
@Data
public class FlySysMenuVO {
    @ApiModelProperty(value = "编号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "名称", example = "系统管理")
    private String name;
    @ApiModelProperty(value = "英文名称", example = "SystemManage")
    private String nameEn;
    @ApiModelProperty(value = "访问url", example = "cogs")
    private String url;
    @ApiModelProperty(value = "父菜单编号", example = "0")
    private Integer parentID;
    @ApiModelProperty(value = "显示顺序", example = "100")
    private Integer sort;
    @ApiModelProperty(value = "是否可见", example = "1")
    private Integer visible;
}
