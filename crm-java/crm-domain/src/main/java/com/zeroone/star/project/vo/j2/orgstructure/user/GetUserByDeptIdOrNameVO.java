package com.zeroone.star.project.vo.j2.orgstructure.user;

import com.zeroone.star.project.vo.j2.orgstructure.user.base.BaseUserVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;

/**
 * 用户列表(分页+条件)展示
 * @author 礼拜一
 * @since 2023/10/20
 */
@Getter
@Setter
@ApiModel(value = "获取用户列表(分页+条件)")
public class GetUserByDeptIdOrNameVO extends BaseUserVO {

    @ApiModelProperty(value = "部门名称")
    private String deptName;

    @ApiModelProperty(value = "岗位名称")
    private String  positionName;

    @ApiModelProperty(value = "角色名称")
    private String  roleName;

    @ApiModelProperty(value = "展示性别")
    private String showGender;
}
