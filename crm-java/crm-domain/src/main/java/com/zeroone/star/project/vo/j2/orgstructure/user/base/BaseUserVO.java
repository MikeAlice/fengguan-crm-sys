package com.zeroone.star.project.vo.j2.orgstructure.user.base;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 系统用户表
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Data
@ApiModel(value = "系统用户表")
public class BaseUserVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "用户ID")
    private Integer id;

    @ApiModelProperty(value = "账号")
    private String account;

    @ApiModelProperty(value = "密码 (加密)")
    private String password;

    @ApiModelProperty(value = "用户昵称")
    private String name;

    @ApiModelProperty(value = "用户性别 (1男，2女)")
    private String gender;

    @ApiModelProperty(value = "用户电话")
    private String tel;

    @ApiModelProperty(value = "用户手机号")
    private String mobile;

    @ApiModelProperty(value = "QQ号")
    private String qicq;

    @ApiModelProperty(value = "地址")
    private String address;

    @ApiModelProperty(value = "邮政编码")
    private String zipcode;

    @ApiModelProperty(value = "邮箱")
    private String email;

    @ApiModelProperty(value = "角色ID")
    private String roleID;

    @ApiModelProperty(value = "部门ID")
    private Integer deptID;

    @ApiModelProperty(value = "岗位ID")
    private Integer positionID;

    @ApiModelProperty(value = "用户介绍")
    private String intro;

    @ApiModelProperty(value = "adt")
    private LocalDateTime adt;

    @ApiModelProperty(value = "身份证号")
    private String identity;

    @ApiModelProperty(value = "用户状态 (0正常，1冻结)")
    private Integer status;

}
