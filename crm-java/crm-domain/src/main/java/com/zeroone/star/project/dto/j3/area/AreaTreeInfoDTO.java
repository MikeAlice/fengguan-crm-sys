package com.zeroone.star.project.dto.j3.area;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.List;

@Data
@ApiModel("区域名称结构树请求实体")
public class AreaTreeInfoDTO extends AreaInfoDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "树名称")
    private String treeName;
    @ApiModelProperty(value = "地区等级（树深度）")
    private Integer level;
    @ApiModelProperty(value = "子地区节点")
    List<AreaTreeInfoDTO> nodes;
}
