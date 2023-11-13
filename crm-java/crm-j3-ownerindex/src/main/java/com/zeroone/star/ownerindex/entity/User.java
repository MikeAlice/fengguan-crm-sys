package com.zeroone.star.ownerindex.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyOwnerInfoDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import java.util.Date;

/**
 * @Description: 用户实体类
 * @Author: your name
 * @Date: 2023/10/24 17:07
 */
@Data
@TableName("fly_sys_user")
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
public class User {

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

    private String roleID;

    private Integer deptID;

    private Integer positionID;

    private String intro;

    private Date adt;

    private String identity;

    private Integer status;

    public User(ModifyOwnerInfoDTO dto) {
        this.name = dto.getName();
        this.gender = dto.getGender();
        this.tel = dto.getTel();
        this.mobile = dto.getMobile();
        this.qicq = dto.getQicq();
        this.address = dto.getAddress();
        this.zipcode = dto.getZipcode();
        this.email = dto.getEmail();
        this.intro = dto.getIntro();
        this.identity = dto.getIdentity();
    }
}
