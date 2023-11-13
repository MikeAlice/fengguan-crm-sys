package com.zeroone.star.project.vo.j2.purchasemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 导出合同VO
 * @author 叔
 * @date 2023/10/31 21:42
 */
@Data
@ApiModel(value = "合同导出VO")
public class ExportContractVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "导出合同excel文件地址")
    private String url;
}
