package com.zeroone.star.purchasemanagement.modules.contract.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 采购合同附件
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Getter
@Setter
@TableName("pos_contract_file")
public class PosContractFileEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 订单项ID
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 合同ID
     */
    private Integer contractId;

    /**
     * 文件名称
     */
    private String name;

    /**
     * 类型
     */
    private String type;

    /**
     * 备注
     */
    private String remarks;

    /**
     * 文件路径
     */
    private String filepath;

    @TableField(fill = FieldFill.INSERT)
    private Integer createUserId;

    @TableField(fill = FieldFill.INSERT)
    private Date createTime;


}
