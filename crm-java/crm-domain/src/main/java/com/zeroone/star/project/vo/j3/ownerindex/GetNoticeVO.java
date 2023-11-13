package com.zeroone.star.project.vo.j3.ownerindex;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description: 查看指定公告详情
 * @Author: 发财
 */
@Data
@ApiModel("查看指定公告传输对象")
public class GetNoticeVO {
//    @ApiModelProperty(value = "编号",example = "1")
//    private Integer id;

    @ApiModelProperty(value = "标题",example = "无标题")
    private String title;

    @ApiModelProperty(value = "通知内容",example = "无内容")
    private String content;

//    @ApiModelProperty(value = "状态",example = "未读")
//    private Integer status;
//
//    @ApiModelProperty(value = "接收人员编号", example = "1")
//    private Integer ownerUserId;
//
//    @ApiModelProperty(value = "发布人员编号编号", example = "1")
//    private Integer createUserId;
//
//    @ApiModelProperty(value = "时间", example = "2020-01-01")
//    private String createTime;
}
