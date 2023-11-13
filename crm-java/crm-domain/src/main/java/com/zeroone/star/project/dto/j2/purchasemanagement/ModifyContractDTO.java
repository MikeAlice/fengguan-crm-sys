package com.zeroone.star.project.dto.j2.purchasemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

@Data
@ApiModel(value = "根据采购合同id获取采购合同基本信息")
public class ModifyContractDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotNull(message = "采购合同id不能为空")
    @Min(value = 1,message = "最小值为1")
    @ApiModelProperty(value = "采购合同id")
    private Integer contractId;
    @NotBlank(message = "合同编号不能为空")
    @ApiModelProperty(value = "合同编号")
    private String contractNo;
    @NotBlank(message = "标题不能为空")
    @ApiModelProperty(value = "标题")
    private String title;
    @NotNull(message = "客户id不能为空")
    @ApiModelProperty(value = "客户id")
    private Integer supplierId;
    @NotNull(message = "客户联系人id不能为空")
    @ApiModelProperty(value = "客户联系人id")
    private Integer linkmanId;
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "采购时间")
    private Date startDate;
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "预计到货时间")
    private Date endDate;
    @NotNull(message = "合同金额不能为空")
    @ApiModelProperty(value = "合同金额")
    private BigDecimal money;
    @ApiModelProperty(value = "订单介绍")
    private String intro;
    @NotNull(message = "我方联系人id不能为空")
    @ApiModelProperty(value = "我方联系人id")
    private Integer ourUserId;
}