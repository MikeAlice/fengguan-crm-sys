package com.zeroone.star.project.dto.j1.systemmanagement;

import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.Map;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("获取所需字段的id信息")
public class CstFieldExtplusDTO {
    @ApiModelProperty(value ="字段id" ,example ="1" )
    private Integer fieldExtId;


    @ApiModelProperty
    private Map<String,String> extField;

    public CstFieldExtplusDTO(String fieldExtId){
        this.fieldExtId=Integer.valueOf(fieldExtId);
    }

}
