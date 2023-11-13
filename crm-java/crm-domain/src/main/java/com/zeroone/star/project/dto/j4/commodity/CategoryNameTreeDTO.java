package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import java.util.LinkedList;
import java.util.List;

@ApiOperation(value = "商品分类名称树，每个分类包含自己的id和名称，以及该分类下的子分类")
@Data
public class CategoryNameTreeDTO {
    @ApiModelProperty("商品分类id")
    private Integer id;
    @ApiModelProperty("商品分类名称")
    private String name;
    @ApiModelProperty("该分类下的子分类")
    private List<CategoryNameTreeDTO> children = new LinkedList<>();;

    public CategoryNameTreeDTO() {
    }

    public CategoryNameTreeDTO(Integer id, String name) {
        this.id = id;
        this.name = name;
    }
}
