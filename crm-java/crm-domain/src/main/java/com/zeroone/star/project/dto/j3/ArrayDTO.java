package com.zeroone.star.project.dto.j3;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.ArrayList;

/**
 * @Description: 共用传id数组
 * @Author: your name
 * @Date: 2023/10/24 21:55
 */
@Data
@ApiModel("用于接收某些批量操作的id数组")
public class ArrayDTO {

    @ApiModelProperty(value = "id数组",example = "[1,2,3]")
    private ArrayList<Integer> ids;
}
