package com.zeroone.star.project.vo.j2.orgstructure.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 用户导出VO
 *
 * @author 汐
 * @since 2023/10/27
 */
@Data
@ApiModel(value = "用户导出VO")
public class UserExportVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "导出用户excel文件地址")
    private String url;
}
