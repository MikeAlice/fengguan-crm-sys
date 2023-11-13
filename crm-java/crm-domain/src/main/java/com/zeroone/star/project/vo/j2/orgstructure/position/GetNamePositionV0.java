package com.zeroone.star.project.vo.j2.orgstructure.position;

import com.zeroone.star.project.vo.j2.orgstructure.position.base.BasePositionVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel(value = "获取岗位名称结构树")
public class GetNamePositionV0 implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "岗位ID")
    private Integer id;
    @ApiModelProperty(value = "岗位名称，例如：&nbsp;&nbsp;|--岗位")
    private  String name;

}
