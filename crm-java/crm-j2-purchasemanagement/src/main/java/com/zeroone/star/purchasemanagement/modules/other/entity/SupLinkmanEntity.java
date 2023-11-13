package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 供应商联系人
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("sup_linkman")
public class SupLinkmanEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "linkman_id", type = IdType.AUTO)
    private Integer linkmanId;

    private Integer supplierId;

    private String name;

    private Integer gender;

    private String postion;

    private String tel;

    private String mobile;

    private String qicq;

    private String email;

    private String zipcode;

    private String address;

    private String intro;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;


}
