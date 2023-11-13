package com.zeroone.star.project.query.j2.purchasemanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * 获取合同列表查询参数
 *
 * @author 汐
 * @since 2023/10/29
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "获取合同列表查询参数")
public class GetContractListWithPageConditionQuery extends PageQuery {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "有效期起始 (如：3d：三天；1m：1月；12m：1年)")
    private String startDate;
    @ApiModelProperty(value = "有效期结束 (如：3d：三天；1m：1月；12m：1年)")
    private String endDate;
    @ApiModelProperty(value = "主题关键字") // 合同标题
    private String name;
    @ApiModelProperty(value = "供应商名称")
    private String supplierName;
    @ApiModelProperty(value = "备注内容")
    private String intro;
}
