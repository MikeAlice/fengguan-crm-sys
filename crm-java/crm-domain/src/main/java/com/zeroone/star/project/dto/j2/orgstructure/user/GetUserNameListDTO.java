package com.zeroone.star.project.dto.j2.orgstructure.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.io.Serializable;

@Data
@ApiModel(value = "系统用户名列表")
public class GetUserNameListDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "用户名称")
    private String name;
}
