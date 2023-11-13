package com.zeroone.star.project.dto.j1.systemindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("公告通知上传对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class noticeRemindDTO {
    /**
     * 通知编号
     */
    @ApiModelProperty(value = "通知编号", required = true)
    private Integer id;

    /**
     * 标题
     */
    @ApiModelProperty(value = "系统通知主题",example = "默认标题",required = true)
    private String title;

    /**
     * 通知消息内容
     */
    @ApiModelProperty(value = "通知内容",example = "默认消息",required = true)
    private String content;

    /**
     * 状态
     */
    @ApiModelProperty(value = "通知状态",example = "-1",required = true)
    private Integer status;
}
