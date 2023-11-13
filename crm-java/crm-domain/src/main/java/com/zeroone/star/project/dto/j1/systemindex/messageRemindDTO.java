package com.zeroone.star.project.dto.j1.systemindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.sql.Timestamp;
import java.util.Date;

@ApiModel("消息通知上传对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class messageRemindDTO {
    /**
     * 消息编号
     */
    @ApiModelProperty(value = "消息编号", required = true)
    private Integer id;

    /**
     * 消息类型
     */
    @ApiModelProperty(value = "消息类型",example = "普通消息",required = true)
    private String msgType;
    /**
     * 标题
     */
    @ApiModelProperty(value = "消息主题",example = "默认标题",required = true)
    private String msgTitle;

    /**
     * 状态
     */
    @ApiModelProperty(value = "消息状态",example = "-1",required = true)
    private Integer flag;

    /**
     * 跳转链接类型
     */
    @ApiModelProperty(value = "跳转链接类型")
    private String urlType;

    /**
     * 跳转链接编号
     */
    @ApiModelProperty(value = "跳转链接")
    private Integer urlId;

    /**
     * 提醒时间
     */
    @ApiModelProperty(value = "提醒时间",required = true)
    private Date remindTime;
}
