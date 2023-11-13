package com.zeroone.star.project.vo.j2.orgstructure.role;

import com.zeroone.star.project.vo.j2.orgstructure.role.base.BaseMenuVO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
public class GetNameRoleVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "角色ID")
    private Integer  id;
    @ApiModelProperty(value = "角色名称，例如：&nbsp;&nbsp;|--角色")
    private  String name;

}
