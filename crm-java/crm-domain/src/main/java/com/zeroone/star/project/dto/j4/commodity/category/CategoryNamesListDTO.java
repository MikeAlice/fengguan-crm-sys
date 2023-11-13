package com.zeroone.star.project.dto.j4.commodity.category;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author zhairenhao
 * @date 2023/10/30 22:41
 * @description
 */
@Data
@ApiModel("商品分类名称列表DTO")
public class CategoryNamesListDTO {

    @ApiModelProperty(value = "商品分类名称",example = "衣服")
    private String categoryName;

}
