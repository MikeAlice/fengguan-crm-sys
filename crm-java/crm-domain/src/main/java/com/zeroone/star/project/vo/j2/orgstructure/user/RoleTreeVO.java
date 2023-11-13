package com.zeroone.star.project.vo.j2.orgstructure.user;

import com.zeroone.star.project.vo.j2.orgstructure.dept.DeptTreeVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.base.BaseRoleVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;
@Data
/**
 * @author: Larry
 * @Date: 2023 /10 /22 / 17:22
 * @Description:
 */
@ApiModel(value = "获取角色结构树")
public class RoleTreeVO extends BaseRoleVO {
    @ApiModelProperty(value = "树名称")
    private String treeName;
    @ApiModelProperty(value = "角色等级(树深度)")
    private Integer level;
    @ApiModelProperty(value = "子部门节点")
    List<RoleTreeVO> nodes;

}
