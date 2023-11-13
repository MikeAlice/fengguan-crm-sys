package com.zeroone.star.project.dto.j3.ownerindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description: 修改密码传输数据对象
 * @Author: 4.5
 * @Date: 2023/10/20 19:49
 */
@Data
@ApiModel("修改密码传输对象")
public class ModifyPwdDTO {

    @ApiModelProperty(value = "旧密码",example = "1111six",required = true)
    private String oldPassword;

    @ApiModelProperty(value = "新密码",example = "1111six",required = true)
    private String newPassword;
}
