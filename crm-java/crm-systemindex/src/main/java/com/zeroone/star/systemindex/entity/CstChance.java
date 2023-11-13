package com.zeroone.star.systemindex.entity;


import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * 销售机会
 * @TableName cst_chance
 */
@TableName(value ="cst_chance")
@Data
public class CstChance implements Serializable {

    private static final long serialVersionUID = 1L;


    @TableId
    private Integer chanceId;


    private Integer customerId;


    private String linkmanId;

    /**
     * 发现时间
     */
    private Date findDate;

    /**
     * 预计签单时间
     */
    private Date billDate;

    /**
     * 谈判状态
     */
    private Integer salestage;

    /**
     * 预计金额
     */
    private BigDecimal money;

    /**
     * 预计可能性成功率
     */
    private Integer successRate;


    private Integer userid;

    /**
     * 主题
     */
    private String name;


    private String intro;


    private Short status;

    private Integer createUserId;

    private Date createTime;

}