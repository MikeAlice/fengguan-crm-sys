package com.zeroone.star.project.query.j3.ownerindex;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.annotation.format.DateTimeFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Past;
import javax.validation.constraints.Size;

/**
 * @program:IntelliJ IDEA
 * @Description:条件查询公告
 * @author:Mr.CheCheHuiBujianO
 * @data: 2023/10/23 21:26
 */
@Data
@ApiModel("条件查询公告")
public class SearchNoticeQuery extends PageQuery {
//    @Past
//    @DateTimeFormat("yyyy-mm-dd")
//    @ApiModelProperty(value = "创建时间",example = "2019-03-09",required = false,hidden = true)
//    private DateTime createTime;
    @Size(min = 0)
    @ApiModelProperty(value = "公告标题",example = "今晚打老虎",required = false)
    private String title;
    @Size(min = 0)
    @ApiModelProperty(value = "公告内容" ,example = "今晚实行plan b",required = false)
    private String content;

}
