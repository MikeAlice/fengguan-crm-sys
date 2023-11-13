package com.zeroone.star.project.dto.j4.commodity;

import com.zeroone.star.project.dto.j4.commodity.validation.AtLeastOneNotNull;
import com.zeroone.star.project.dto.j4.commodity.validation.UpdateCategory;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;

/**
 * 修改商品分类DTO
 * @author 张二发
 */
@ApiModel(value = "修改商品分类DTO")
@Data
@AtLeastOneNotNull(message = "未进行任何修改", groups = UpdateCategory.class)
public class UpdateGoodsCategoryDTO extends AddGoodsCategoryDTO{
    @ApiModelProperty(value = "分类ID", example = "1", required = true)
    @NotNull(message = "分类ID不能为空", groups = UpdateCategory.class)
    private Integer id;

    public UpdateGoodsCategoryDTO() {
        super();
    }

    public UpdateGoodsCategoryDTO(int id, String name, String shortName, int parentId, int sortIndex, String description, String keywords, int visible) {
        super(name, shortName, parentId, sortIndex, description, keywords, visible);
        this.id = id;
    }
}
