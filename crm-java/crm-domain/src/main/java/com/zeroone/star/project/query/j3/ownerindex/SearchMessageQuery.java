package com.zeroone.star.project.query.j3.ownerindex;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.NotBlank;

/**
 * @BelongsProject: crm-java
 * @BelongsPackage: com.zeroone.star.project.dto.j3.message
 * @Author: ZhangJF
 * @CreateTime: 2023-10-20  15:22
 * @Description: 描述：查询消息数据的对象
 * @Version: 1.0
 */
@Validated
@Data
@ApiModel("查询消息数据")
public class SearchMessageQuery extends PageQuery {
    @ApiModelProperty(value = "消息类型",required = false)
    private String msgType;
    @ApiModelProperty(value = "消息是否被处理",required = false)
    private Integer flag;
    @ApiModelProperty(value = "关键字",required = false)
    private String keyWord;
}
