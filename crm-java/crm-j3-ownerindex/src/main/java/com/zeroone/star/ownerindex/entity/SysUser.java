package com.zeroone.star.ownerindex.entity;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;

/**
 * @program:IntelliJ IDEA
 * @Description:部门类
 * @author:Mr.CheCheHuiBujianO
 * @data: 2023/10/27 14:24
 */
@Data
@TableName("fly_sys_user")
@Getter
public class SysUser {
    @TableId(value = "id",type = IdType.AUTO)
    private Integer id;
    private String account;
    private String password;
//    private String name;
    private String gender;
    private String tel;
    private String mobile;
    private String qicq;
    private String address;
    private String zipcode;
    private String email;
    private String roleId;
    private Integer deptId;
    private Integer positionId;
    private String intro;
    private String identity;
    private Integer status;
    @TableField(select = false)
    private DateTime adt;

}
