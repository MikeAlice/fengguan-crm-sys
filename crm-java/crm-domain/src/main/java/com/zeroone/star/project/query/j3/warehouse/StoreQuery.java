package com.zeroone.star.project.query.j3.warehouse;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;

/**
 * @BelongsProject: crm-java
 * @Author: INT
 * @Description: 描述：查询仓库数据的对象
 * @Version: 1.0
 */
@Data
@ApiModel("查询仓库数据")
public class StoreQuery extends PageQuery {

//    @ApiModelProperty(value = "仓库名字", example = "仓库1", required = false)
//    private String name;
    @ApiModelProperty(value = "关键字")
    private String keyWord;
}
