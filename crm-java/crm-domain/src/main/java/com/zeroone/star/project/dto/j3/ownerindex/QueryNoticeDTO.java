package com.zeroone.star.project.dto.j3.ownerindex;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @program:IntelliJ IDEA
 * @Description:公告通知
 * @author:Mr.CheCheHuiBujianO
 * @data: 2023/10/22 1:27
 */
@ApiModel("公告操作数据对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class QueryNoticeDTO {
    @ApiModelProperty(value = "公告id",example = "1888",required = true)
    private Integer id;
    @ApiModelProperty(value = "公告标题",example = "今晚打老虎",required = true)
    private String title;
    @ApiModelProperty(value = "公告内容" ,example = "今晚实行plan b",required = false)
    private String content;
    @ApiModelProperty(value = "查看状态",example = "已经查看 | 还未查看 ", required = false)
    private Integer status;
    @ApiModelProperty(value = "接收人id",example = "11",required = false)
    private Integer ownerUserId;
    @ApiModelProperty(value = "创建人id",example = "22",required = true)
    private Integer createUserId;
    @ApiModelProperty(value = "创建时间",example = "2019-03-09 22:45:06",required = true)
    private DateTime createTime;


}
