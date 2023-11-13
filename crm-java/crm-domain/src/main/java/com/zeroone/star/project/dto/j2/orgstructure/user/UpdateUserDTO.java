package com.zeroone.star.project.dto.j2.orgstructure.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.io.Serializable;

/**
 * 用户请求体参数
 *
 * @author 汐
 * @since 2023/10/20
 */
@Data
@ApiModel(value = "用户请求体参数")
public class UpdateUserDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotNull(message = "用户ID不能为空")
    @ApiModelProperty(value = "用户ID", required = true)
    private Integer id;
    @NotBlank(message = "账号不能为空")
    @ApiModelProperty(value = "账号", required = true)
    private String account;
    @ApiModelProperty(value = "密码 (为空则不修改密码)")
    private String password;
    @NotBlank(message = "用户昵称不能为空")
    @ApiModelProperty(value = "用户昵称", required = true)
    private String name;
    @NotBlank(message = "性别不能为空")
    @Min(value = 1, message = "性别范围为1-2")
    @Max(value = 2, message = "性别范围为1-2")
    @ApiModelProperty(value = "性别 (1-男，2-女)", required = true)
    private String gender;
    @NotNull(message = "部门ID不能为空")
    @ApiModelProperty(value = "部门ID", required = true)
    private Integer deptID;
    @NotNull(message = "岗位ID不能为空")
    @ApiModelProperty(value = "岗位ID", required = true)
    private Integer positionID;
    @NotNull(message = "角色ID不能为空")
    @ApiModelProperty(value = "角色ID", required = true)
    private Integer roleID;
    @ApiModelProperty(value = "手机号")
    private String mobile;
    @ApiModelProperty(value = "qq号")
    private String qicq;
    @ApiModelProperty(value = "邮箱")
    private String email;
    @ApiModelProperty(value = "简介")
    private String intro;
}
