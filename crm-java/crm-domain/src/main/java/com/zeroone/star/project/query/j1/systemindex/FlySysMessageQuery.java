package com.zeroone.star.project.query.j1.systemindex;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class FlySysMessageQuery extends PageQuery {
    @ApiModelProperty(value = "消息类型")
    private String msgType;


}
