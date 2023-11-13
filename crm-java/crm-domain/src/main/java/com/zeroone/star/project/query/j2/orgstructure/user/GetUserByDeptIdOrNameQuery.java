package com.zeroone.star.project.query.j2.orgstructure.user;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;


/**
 * 此类为查询参数的封装
 * @author 礼拜一
 * @since 2023/10/20
 */
//@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("获取用户列表(分页+条件)")
public class GetUserByDeptIdOrNameQuery extends PageQuery {

    /**
     * 当姓名为空时，调用查询全部用户的方法
     */
    @ApiModelProperty(value = "姓名", example = "test")
    private String name;

    /**
     *  前端页面部门树必须用到部门id，所以部门id不能为空
     */
    @NotNull(message = "部门id不能为空")
    @ApiModelProperty(value = "部门id", example = "1")
    private Integer deptId;
}
