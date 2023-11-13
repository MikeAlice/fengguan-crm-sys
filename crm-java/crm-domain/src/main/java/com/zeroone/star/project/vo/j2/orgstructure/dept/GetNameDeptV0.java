package com.zeroone.star.project.vo.j2.orgstructure.dept;

import com.zeroone.star.project.vo.j2.orgstructure.dept.base.BaseDeptVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel(value = "获取部门名称结构树")
public class GetNameDeptV0 implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "部门ID")
    private Integer  id;
    @ApiModelProperty(value = "部门名称，例如：&nbsp;&nbsp;|--技术部")
    private  String name;
}
