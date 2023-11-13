package com.zeroone.star.project.vo.j2.purchasemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.vo.j2.purchasemanagement.base.BasePosContractVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * 合同列表分页模型
 *
 * @author 汐
 * @since 2023/10/29
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "合同列表分页模型")
public class GetContractListWithPageConditionVO extends PageDTO<GetContractListWithPageConditionVO.ContractVO> {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "合同金额统计信息")
    private ContractMoneyStatistic contractMoney;

    @Data
    public static class ContractMoneyStatistic implements Serializable {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "合同金额合计")
        private BigDecimal totalMoney;
        @ApiModelProperty(value = "去零金额合计")
        private BigDecimal totalZeroMoney;
        @ApiModelProperty(value = "付款金额合计")
        private BigDecimal totalPayMoney;
        @ApiModelProperty(value = "欠款金额合计")
        private BigDecimal totalOweMoney;
    }

    @Data
    @EqualsAndHashCode(callSuper = true)
    @ApiModel(value = "采购合同信息")
    public static class ContractVO extends BasePosContractVO {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty("合同主题")
        private String title;
        @ApiModelProperty(value = "供应商名称")
        private String supplierName; //
        @ApiModelProperty(value = "供应商代表")
        private String supplierLinkmanName; //
        @ApiModelProperty("付款")
        private BigDecimal goodsMoney;
        @ApiModelProperty("去零")
        private BigDecimal zeroMoney;
        @ApiModelProperty("欠款")
        private BigDecimal oweMoney;
        @ApiModelProperty("支付状态")
        private String showPayStatus; //
        @ApiModelProperty("收票")
        private BigDecimal invoiceMoney;
        @ApiModelProperty("收票状态")
        private String showInvoiceStatus; //
        @ApiModelProperty("采购时间")
        @JsonFormat(pattern = "yyyy-MM-dd")
        private Date startDate;
        @ApiModelProperty("预订到货时间")
        @JsonFormat(pattern = "yyyy-MM-dd")
        private Date endDate;
        @ApiModelProperty("合同状态")
        private String showStatus; //
        @ApiModelProperty("收货状态")
        private String showReceStatus; //
        @ApiModelProperty(value = "我方代表")
        private String ourUserName; //
        @ApiModelProperty(value = "是否显示查看清单操作：1=显示；2=不显示")
        private Integer isShowViewList; //
        @ApiModelProperty(value = "是否显示录入明细操作：1=显示；2=不显示")
        private Integer isShowEntryList; //
        @ApiModelProperty(value = "是否显示生成入库单操作：1=显示；2=不显示")
        private Integer isShowGenerateInto; //
        @ApiModelProperty(value = "是否显示删除明细操作：1=显示；2=不显示")
        private Integer isShowDeleteList; //
        @ApiModelProperty(value = "是否显示删除操作：1=显示；2=不显示")
        private Integer isShowDelete; //
        @ApiModelProperty(value = "是否显示修改合同操作：1=显示；2=不显示")
        private Integer isShowUpdateContract; //
    }
}
