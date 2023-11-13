package com.zeroone.star.project.vo.j2.purchasemanagement;

import com.zeroone.star.project.vo.j2.purchasemanagement.base.BasePosContractListVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.List;

@Data
@ApiModel(value="合同清单VO模型")
public class GetContractInventoryVO implements Serializable {
    private static final long  serialVersionUID = 1L;

    @ApiModelProperty(value = "合同清单数据")
    private List<BasePosContractListVO> list;

    @ApiModelProperty(value = "合计统计数据")
    private TotalCount totalCount;

/*    @Data
    @EqualsAndHashCode(callSuper = true)
    public static class ContractInventoryData extends BasePosContractListVO{
        private static final long  serialVersionUID = 1L;
    }*/

    @Data
    public static class TotalCount implements Serializable {
        private static final long  serialVersionUID = 1L;

        @ApiModelProperty(value = "合计商品总价")
        private BigDecimal totalGoodsMoney;

        @ApiModelProperty(value = "合计购买数量")
        private String totalNum;
    }
}
