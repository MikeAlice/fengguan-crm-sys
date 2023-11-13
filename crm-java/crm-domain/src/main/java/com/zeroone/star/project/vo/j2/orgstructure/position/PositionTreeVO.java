package com.zeroone.star.project.vo.j2.orgstructure.position;

import com.zeroone.star.project.vo.j2.orgstructure.dept.DeptTreeVO;
import com.zeroone.star.project.vo.j2.orgstructure.position.base.BasePositionVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author: Larry
 * @Date: 2023 /10 /22 / 8:24
 * @Description:
 */
@Data
@ApiModel(value = "获取岗位结构树")
public class PositionTreeVO extends BasePositionVO {
    @ApiModelProperty(value = "树名称")
    private String treeName;
    @ApiModelProperty(value = "部门等级(树深度)")
    private Integer level;
    @ApiModelProperty(value = "子部门节点")
    List<PositionTreeVO> nodes;
}
