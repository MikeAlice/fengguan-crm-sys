package com.zeroone.star.project.dto.j4.commodity;

import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * 查询商品简单类型DTO
 * @author Ak5ma1
 */
@Data
@ApiModel("简单类型信息对象")
public class SimpleTypeInfoDTO {
    @ApiModelProperty(value = "类型名称",example = "硬盘")
    private String attrName;
    @TableField(exist = false)
    @ApiModelProperty(value = "属性标签",example = "大小")
    private List<String> attrValueName;
    @ApiModelProperty(value = "启用",example = "true")
    private boolean visible;
    @ApiModelProperty(value = "排序",example = "1")
    private int sort;
    @ApiModelProperty(value="类型名称ID",example = "1")
    private int attrId;
}
