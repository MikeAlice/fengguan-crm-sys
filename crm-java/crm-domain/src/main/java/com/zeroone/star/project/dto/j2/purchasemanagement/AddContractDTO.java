package com.zeroone.star.project.dto.j2.purchasemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.*;
import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * @author 叔
 * @date 2023/10/30 21:20
 */
@Data
@ApiModel(value = "添加合同传输对象")
public class AddContractDTO implements Serializable {

    @ApiModelProperty(value = "合同编号", example = "202012222111")
    @NotNull(message = "合同编号不能为空")
    private String contractNo;

    @ApiModelProperty(value = "合同标题")
    private String title;

    @ApiModelProperty(value = "供应商id")
    private Integer supplierId;

    @NotNull(message = "客户联系人id不能为空")
    @ApiModelProperty(value = "客户联系人id")
    private Integer linkmanId;

    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "采购时间")
    private Date startDate;

    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "预计到货时间")
    private Date endDate;

    @ApiModelProperty(value = "合同金额")
    private BigDecimal money;

    @ApiModelProperty(value = "订单介绍")
    private String intro;

    @NotNull(message = "我方联系人id不能为空")
    @ApiModelProperty(value = "我方联系人id")
    private Integer ourUserId;

}
