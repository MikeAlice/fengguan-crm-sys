package com.zeroone.star.systemindex.entity;


import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

/**
 * 客户信息表
 * @TableName cst_customer
 */

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName(value = "cst_customer")
public class CstCustomer implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId
    private Integer customerId;

    /**
     * 客户名称
     */
    private String name;

    /**
     * 客户编号
     */
    private String customerNo;

    /**
     * 创建人员
     */
    private Integer createUserId;

    /**
     * 归属人员
     */
    private Integer ownerUserId;


    private Date createTime;

    /**
     * 下次沟通时间
     */
    private Date nextTime;

    /**
     * 最近联系时间
     */
    private Date connTime;

    /**
     * 最近沟通内容
     */
    private String connBody;

    /**
     * 客户代表
     */
    private String linkman;

    /**
     * 客户来源
     */
    private String source;

    /**
     * 客户等级
     */
    private String grade;

    /**
     * 客户行业
     */
    private String industry;

    /**
     * 联系手机
     */
    private String mobile;

    /**
     * 联系电话
     */
    private String tel;

    /**
     * 联系地址
     */
    private String address;

    /**
     * 客户介绍
     */
    private String intro;

    /**
     * 客户需求
     */
    private String needs;



}