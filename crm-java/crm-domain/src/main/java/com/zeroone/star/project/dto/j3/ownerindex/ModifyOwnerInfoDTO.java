package com.zeroone.star.project.dto.j3.ownerindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description: 编辑个人资料
 * @Author: your name
 * @Date: 2023/10/20 20:26
 */

@Data
@ApiModel("编辑个人资料传输对象")
public class ModifyOwnerInfoDTO {

    @ApiModelProperty(value = "姓名",example = "4.5",required = false)
    private String name;

    @ApiModelProperty(value = "性别",example = "男",required = false)
    private String gender;

    @ApiModelProperty(value = "电话号码",example = "1888888888",required = false)
    private String tel;

    @ApiModelProperty(value = "固定电话",example = "6888888",required = false)
    private String mobile;

    @ApiModelProperty(value = "qq",example = "1149670811",required = false)
    private String qicq;

    @ApiModelProperty(value = "地址",example = "清华大学",required = false)
    private String address;

    @ApiModelProperty(value = "邮政编码",example = "111111",required = false)
    private String zipcode;

    @ApiModelProperty(value = "电子邮箱",example = "111111@qq.com",required = false)
    private String email;

    @ApiModelProperty(value = "简介",example = "成功人士",required = false)
    private String intro;

    @ApiModelProperty(value = "身份",example = "程序员炒粉责任无限公司经理",required = false)
    private String identity;
}
