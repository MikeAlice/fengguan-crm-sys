package com.zeroone.star.project.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiParam;
import lombok.Data;

/**
 * @Description: 关键字查询
 * @Author: your name
 * @Date: 2023/11/8 17:00
 */
@Data
@ApiModel("关键字查询")
public class KeyWordQuery {

    @ApiParam(value = "关键字",example = "仓库1",required = false)
    private String keyWord;
}
