package com.zeroone.star.orgstructure.modules.user.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 员工档案
 * </p>
 *
 * @author j2
 * @since 2023-10-25
 */
@Getter
@Setter
@TableName("hrm_staff")
public class StaffEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 员工编号
     */
    private String staffNo;

    private String name;

    /**
     * 姓别1=男，0=女
     */
    private Integer gender;

    /**
     * 身份证号
     */
    private String idcard;

    /**
     * 年龄
     */
    private Integer age;

    /**
     * 部门
     */
    private String deptId;

    /**
     * 职务
     */
    private String positionId;

    /**
     * 婚姻情况
     */
    private String marriage;

    /**
     * 政治面貌
     */
    private String politics;

    /**
     * 最高学历
     */
    private String degree;

    /**
     * 就读专业
     */
    private String major;

    /**
     * 职业资格
     */
    private String qualification;

    /**
     * 工作职务
     */
    private String position;

    /**
     * 社会职
     */
    private String social;

    private String mobile;

    private String qicq;

    private String email;

    private String zipcode;

    private String address;

    private String intro;

    private Integer createUserId;

    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;


}
