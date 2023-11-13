package com.zeroone.star.project.query.j1.systemmanagement;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;
/**
 * @author dzcgood
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("系统菜单查询对象")
public class FlySysMenuQuery extends PageQuery {
    @NotBlank(message = "系统菜单id不能为空")
    @ApiModelProperty(value = "系统菜单id", example = "1")
    private String id;
}