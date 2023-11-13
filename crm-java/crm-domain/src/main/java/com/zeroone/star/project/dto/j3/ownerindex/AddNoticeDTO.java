package com.zeroone.star.project.dto.j3.ownerindex;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description: 发布公告传输数据对象
 * @Author: 4.5
 * @Date: 2023/10/21 18:08
 */
@Data
@ApiModel("发布公告传输对象")
public class AddNoticeDTO {

    @ApiModelProperty(value = "标题", example = "下班", required = true)
    private String title;

    @ApiModelProperty(value = "内容", example = "七点半，01烧烤店集合", required = true)
    private String content;

    @ApiModelProperty(value = "接收人id", example = "01", required = false, notes = "owner_user_id和owner_dept_id必须有一个为有值，可以其中一个为空或者两个都填")
    private Integer ownerUserId;

    @ApiModelProperty(value = "接收部门id", example = "01", required = false, notes = "owner_user_id和owner_dept_id必须有一个为有值，可以其中一个为空或者两个都填")
    private Integer ownerDeptId;

//    @ApiModelProperty(value = "创建人id", example = "22", required = true)
//    private Integer createUserId;

//    @ApiModelProperty(value = "查看状态", example = "1", required = true)
//    private Integer status;

}
