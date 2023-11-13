package com.zeroone.star.project.dto.j3.warehouse;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

/**
 * @Description: 导入仓库数据传输对象
 * @Author: your name
 * @Date: 2023/10/22 16:11
 */
@Data
@ApiModel("导入仓库数据传输对象")
public class ImportStoreDTO {

    @ApiModelProperty(value = "excel文件",example = "xxx.xlsx",required = true,notes = "前端要进行文件限制")
    private MultipartFile excelFile;
}
