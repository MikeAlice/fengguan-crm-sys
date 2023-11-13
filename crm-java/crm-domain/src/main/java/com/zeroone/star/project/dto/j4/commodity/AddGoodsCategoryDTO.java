package com.zeroone.star.project.dto.j4.commodity;

import com.zeroone.star.project.dto.j4.commodity.validation.AddCategory;
import com.zeroone.star.project.dto.j4.commodity.validation.AtLeastOneNotNull;
import com.zeroone.star.project.dto.j4.commodity.validation.UpdateCategory;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

/**
 * 添加商品分类DTO
 * @author 张二发
 */
@Data
@ApiModel(value = "添加和修改商品分类DTO")
public class AddGoodsCategoryDTO {
    @ApiModelProperty(value = "分类名称", example = "基础业务", required = true)
    @NotBlank(message = "分类名称不能为空", groups = AddCategory.class)
    private String name;
    @ApiModelProperty(value = "分类简称", example = "基础业务", required = true)
    @NotBlank(message = "分类简称不能为空", groups = AddCategory.class)
    private String shortName;
    @ApiModelProperty(value = "父级分类ID", example = "0", required = true)
    @Min(value = 0, message = "父类不存在", groups = AddCategory.class)
    private Integer parentId;
    @ApiModelProperty(value = "排序序号", example = "1", required = true)
    @Min(value = 0, message = "排序序号需要＞0", groups = AddCategory.class)
    private Integer sortIndex;
    @ApiModelProperty(value = "分类描述", example = "基础业务", required = true)
    @NotBlank(message = "分类描述不能为空", groups = AddCategory.class)
    private String description;
    @ApiModelProperty(value = "分类状态:是否启用", example = "true", required = true)
    @NotNull(groups = AddCategory.class)
    private Boolean visible;
    @ApiModelProperty(value = "分类关键字", example = "基础业务", required = true)
    @NotBlank(message = "分类关键字不能为空", groups = AddCategory.class)
    private String keywords;

    public AddGoodsCategoryDTO() {
    }

    public AddGoodsCategoryDTO(String name, String shortName, int parentId, int sortIndex, String description, String keywords, int visible) {
        this.name = name;
        this.shortName = shortName;
        this.parentId = parentId;
        this.sortIndex = sortIndex;
        this.description = description;
        this.keywords = keywords;
        this.visible = visible == 1;
    }
}