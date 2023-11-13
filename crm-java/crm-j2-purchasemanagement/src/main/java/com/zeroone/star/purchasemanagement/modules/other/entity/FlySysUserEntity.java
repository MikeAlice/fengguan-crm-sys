package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 系统用户表
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("fly_sys_user")
public class FlySysUserEntity implements Serializable {

    private static final long serialVersionUID = 1L;

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

    @TableField("roleID")
    private String roleID;

    @TableField("deptID")
    private Integer deptID;

    @TableField("positionID")
    private Integer positionID;

    private String intro;

    private Date adt;

    private String identity;

    /**
     * 账号状态 0=正常，1=冻结
     */
    private Integer status;


}
