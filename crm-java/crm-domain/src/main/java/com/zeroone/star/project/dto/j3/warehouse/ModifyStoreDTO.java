package com.zeroone.star.project.dto.j3.warehouse;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：修改仓库传输数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 巧克力张张包
 * @version 1.0.0
 */


@Data
@ApiModel("修改仓库")
public class ModifyStoreDTO {

    @ApiModelProperty(value = "storeId，唯一识别号", example = "1",required = true,notes = "后续字段必须起码有一个不为空不然，不让请求，麻烦前端兄弟判断一下了")
    private Integer storeId;

    @ApiModelProperty(value = "仓库名称", example = "仓库1", required = false)
    private String name;

    @ApiModelProperty(value = "排位序号", example = "1", required = false)
    private Integer sort;

    @ApiModelProperty(value = "是否启用", example = "1", required = false)
    private Integer visible;

    @ApiModelProperty(value = "简介", example = "这是一个大仓库")
    private String intro;


}