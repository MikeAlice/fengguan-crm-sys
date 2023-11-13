package com.zeroone.star.project.vo.j2.purchasemanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.vo.j2.purchasemanagement.base.BasePosContractListVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * <p>
 * 描述：明细列表分页模型
 * </p>
 *
 * @author 望三星
 * @version 1.0.0
 * @date 2023/10/31
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "明细列表分页模型")
public class GetContractListPageVO extends PageDTO<GetContractListPageVO.ContractListVO> {

    @ApiModelProperty(value = "采购明细统计信息")
    private TotalStatistic totalStatistic;

    @Data
    public static class TotalStatistic implements Serializable {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "采购明细-购买数量合计")
        private Integer totalNum;

        @ApiModelProperty(value = "采购明细-金额合计")
        private BigDecimal totalOweMoney;

        @ApiModelProperty(value = "采购明细-入库数量合计")
        private Integer totalIntoNum;
    }

    @Data
    @EqualsAndHashCode(callSuper = true)
    @ApiModel(value = "采购明细信息")
    public static class ContractListVO extends BasePosContractListVO implements Serializable {
        private static final long serialVersionUID = 1L;

        // 此处前端显示为《采购单号》，实际显示为合同主题
        @ApiModelProperty("合同主题")
        private String title;
    }
}
