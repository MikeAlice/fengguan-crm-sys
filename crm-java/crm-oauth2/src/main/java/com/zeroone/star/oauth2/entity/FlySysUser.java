package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * @TableName fly_sys_user
 */
@TableName(value ="fly_sys_user")
@Data
public class FlySysUser implements Serializable {

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String account;

    private String password;

    private String name;

    private String gender;

    private String tel;

    private String mobile;

    private String qicq;

    private String address;

    private String zipcode;

    private String email;

    private String roleid;

    private Integer deptid;

    private Integer positionid;

    private String intro;

    private Date adt;

    private String identity;

    private Integer status;

    private static final long serialVersionUID = 1L;
}