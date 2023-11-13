package com.zeroone.star.project.dto.j3.ownerindex;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import java.time.LocalDate;

/**
 * @Description: 发布消息的传输对象
 * @Author: Laputa
 * @CreateTime: 2023-10-26  13:37
 * @Version: 1.0
 */
@Data
public class AddMessageDTO {

    @ApiModelProperty(value = "消息类型", example = "Type", required = true)
    private String msgType;

    @ApiModelProperty(value = "消息主题", example = "Title", required = true)
    private String msgTitle;

    @ApiModelProperty(value = "URL类型", example = "URLType", required = true)
    private String urlType;

    @Min(value = 1, message = "编号不能小于1")
    @ApiModelProperty(value = "URL编号", example = "1", required = true)
    private Integer urlId;

    @ApiModelProperty(value = "所属用户编号", example = "1", required = true)
    private Integer ownerUserId;

    @ApiModelProperty(value = "提醒时间", example = "2023-10-20 13:00:00", required = true)
    private String remindTime;
}
