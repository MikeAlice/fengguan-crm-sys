package com.zeroone.star.project.vo.j2.purchasemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.vo.j2.purchasemanagement.base.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;
import java.util.List;

/**
 * 合同详情vo模型
 *
 * @author 汐
 * @since 2023/10/29
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "合同详情vo模型")
public class GetContractDetailVO extends BasePosContractVO {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty("付款金额")
    private BigDecimal payMoney;
    @ApiModelProperty("开始时间")
    @JsonFormat(pattern = "yyyy-MM-dd")
    private Date startDate;
    @ApiModelProperty(value = "结束时间")
    @JsonFormat(pattern = "yyyy-MM-dd")
    private Date endDate;
    @ApiModelProperty("采购备注")
    private String intro;
    @ApiModelProperty(value = "创建时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date createTime;
    @ApiModelProperty(value = "供应商名称")
    private String supplierName; //
    @ApiModelProperty(value = "联系代表")
    private String supplierLinkmanName; //
    @ApiModelProperty(value = "我方代表")
    private String ourUserName; //
    @ApiModelProperty(value = "合同状态")
    private String showStatus; //

    @ApiModelProperty(value = "合计统计信息")
    private TotalStatistic totalStatistic;

    @ApiModelProperty(value = "采购明细")
    private List<PurchaseDetail> purchaseDetailList;
    @ApiModelProperty(value = "付款记录")
    private List<PayRecord> payRecordList;
    @ApiModelProperty(value = "收票记录")
    private List<InvoiceRecord> invoiceRecordList;
    @ApiModelProperty(value = "合同附件")
    private List<ContractFile> contractFileList;

    @Data
    public static class TotalStatistic implements Serializable {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "采购明细-数量合计")
        private Integer purchaseTotalNum;
        @ApiModelProperty(value = "采购明细-小计合计")
        private BigDecimal purchaseSubtotal;
        @ApiModelProperty(value = "付款记录-金额合计")
        private BigDecimal payTotalMoney;
        @ApiModelProperty(value = "收票记录-金额合计")
        private BigDecimal invoiceTotalMoney;
    }

    @Data
    @EqualsAndHashCode(callSuper = true)
    public static class PurchaseDetail extends BasePosContractListVO {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "商品规格")
        private String skuName;
        @ApiModelProperty("进货价格")
        private BigDecimal costPrice;
        @ApiModelProperty("数量")
        private String num;
        @ApiModelProperty("小计")
        private BigDecimal goodsMoney;
    }

    @Data
    @EqualsAndHashCode(callSuper = true)
    public static class PayRecord extends BaseFinPayRecordVO {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "供应商")
        private String supplierName;
        @ApiModelProperty(value = "采购合同")
        private String contractName;
        @ApiModelProperty(value = "付款时间")
        @JsonFormat(pattern = "yyyy-MM-dd")
        private Date payDate;
        @ApiModelProperty(value = "期次")
        private Integer stages;
        @ApiModelProperty(value = "金额")
        private BigDecimal money;
        @ApiModelProperty(value = "去零")
        private BigDecimal zeroMoney;
        @ApiModelProperty(value = "创建人")
        private String createUserName; //
        @ApiModelProperty(value = "创建时间")
        @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
        private Date createTime;
        @ApiModelProperty(value = "备注")
        private String intro;
    }

    @Data
    @EqualsAndHashCode(callSuper = true)
    public static class InvoiceRecord extends BaseFinInvoiceReceVO {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "供应商")
        private String supplierName;
        @ApiModelProperty(value = "合同单号")
        private String contractName;
        @ApiModelProperty(value = "发票金额")
        private Integer money;
        @ApiModelProperty("收票时间")
        @JsonFormat(pattern = "yyyy-MM-dd")
        private Date receDate;
        @ApiModelProperty(value = "期次")
        private Integer stages;
        @ApiModelProperty(value = "创建人")
        private String createUserName; //
        @ApiModelProperty(value = "备注")
        private String intro;
    }

    @Data
    @EqualsAndHashCode(callSuper = true)
    public static class ContractFile extends BasePosContractFileVO {
        private static final long serialVersionUID = 1L;
    }
}
