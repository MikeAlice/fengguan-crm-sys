package com.zeroone.star.project.vo.j2.purchasemanagement.base;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * 采购合同附件基本vo模型
 *
 * @author j2
 * @since 2023/10/29
 */
@Data
@ApiModel(value = "采购合同附件基本vo模型")
public class BasePosContractFileVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "采购合同附件ID")
    private Integer id;

    @ApiModelProperty(value = "合同ID")
    private Integer contractId;

    @ApiModelProperty(value = "文件名称")
    private String name;

    @ApiModelProperty(value = "类型")
    private String type;

    @ApiModelProperty(value = "备注")
    private String remarks;

    @ApiModelProperty(value = "文件路径")
    private String filepath;

    @ApiModelProperty(value = "创建用户ID")
    private Integer createUserId;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;
}
