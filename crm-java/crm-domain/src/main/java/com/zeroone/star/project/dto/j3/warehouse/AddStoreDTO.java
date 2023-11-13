package com.zeroone.star.project.dto.j3.warehouse;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;

/**
 * <p>
 * 描述：新增仓库传输数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author INT
 * @version 1.0.0
 */
@Data
@ApiModel("添加仓库")
public class AddStoreDTO {
    @NotNull
    @ApiModelProperty(value = "仓库名称", example = "仓库1", required = true)
    private String name;
    @ApiModelProperty(value = "排位序号", example = "1", required = true)
    private Integer sort;
    @ApiModelProperty(value = "是否启用", example = "1", required = true,notes = "1启动仓库,0关闭")
    private Integer visible;
    @ApiModelProperty(value = "简介", example = "添加的仓库")
    private String intro;
}
