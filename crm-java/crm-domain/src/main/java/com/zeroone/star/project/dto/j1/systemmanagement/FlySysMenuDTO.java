package com.zeroone.star.project.dto.j1.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @author DzcGood
 * @date 2023/10/20 - 15:45
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
@ApiModel("系统菜单栏目传输数据对象")
public class FlySysMenuDTO {
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
