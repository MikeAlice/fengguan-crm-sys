package com.zeroone.star.project.vo.j2.purchasemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 导出合同明细excel表格文件地址vo
 *
 * @author 汐
 * @since 2023/10/31
 */
@Data
@ApiModel(value = "导出合同明细excel表格文件地址vo")
public class ExportContractDetailVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "excel文件地址")
    private String url;
}
