package com.zeroone.star.project.vo.j2.orgstructure.dept;

import com.zeroone.star.project.vo.j2.orgstructure.dept.base.BaseDeptVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;
@Data
/**
 * @author: Larry
 * @Date: 2023 /10 /21 / 12:40
 * @Description:
 */
@ApiModel(value = "获取部门结构树")
public class DeptTreeVO extends BaseDeptVO {
    @ApiModelProperty(value = "树名称")
    private String treeName;
    @ApiModelProperty(value = "部门等级(树深度)")
    private Integer level;
    @ApiModelProperty(value = "子部门节点")
    List<DeptTreeVO> nodes;
}
