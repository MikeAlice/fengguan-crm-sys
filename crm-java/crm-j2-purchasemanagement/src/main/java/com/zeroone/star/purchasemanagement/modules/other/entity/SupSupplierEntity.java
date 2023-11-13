package com.zeroone.star.purchasemanagement.modules.other.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 供应商
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("sup_supplier")
public class SupSupplierEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "supplier_id", type = IdType.AUTO)
    private Integer supplierId;

    private String name;

    /**
     * 所在地区
     */
    private Integer areaId;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;

    /**
     * 客户等级
     */
    private Integer level;

    /**
     * 经济类型
     */
    private Integer ecotype;

    /**
     * 行业
     */
    private Integer trade;

    /**
     * 满意度（1-5），默认为3
     */
    private Integer satisfy;

    /**
     * 信用度（1-5），默认为3
     */
    private Integer credit;

    private String address;

    private String linkman;

    private String website;

    private String zipcode;

    private String tel;

    private String fax;

    private String email;

    private String intro;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    /**
     * test
     */
    private String test;


}
