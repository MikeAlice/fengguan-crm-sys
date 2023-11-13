package com.zeroone.star.project.dto.j2.orgstructure.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


import javax.validation.constraints.NotNull;
import java.io.Serializable;


/**
 * 用户请求体参数id
 * @author 礼拜一
 * @since 2023/10/20
 */
@Data
@ApiModel(value = "获取用户请求参数id")
public class ModifyUserStatusDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotNull(message = "用户id不能为空")
    @ApiModelProperty(value = "用户ID",example = "1")
    private Integer id;
}
