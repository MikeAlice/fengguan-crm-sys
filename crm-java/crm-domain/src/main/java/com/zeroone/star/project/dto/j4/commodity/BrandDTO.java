package com.zeroone.star.project.dto.j4.commodity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;

/**
 *   描述： 操作品牌数据的传输对象
 */
@Data
@ApiModel("操作品牌数据的传输对象品牌")
public class BrandDTO {
    @ApiModelProperty(value = "商品的Id",example = "1")
    private  Long brandId;

    @NotBlank(message = "商品的品牌不为空")
    @ApiModelProperty(value = "品牌名称", example = "小米")
    private String brandName;

    @ApiModelProperty(value = "品牌首字母", example = "X")
    private String brandInitial;

    @ApiModelProperty(value = "品牌图片链接", example = "https://xxx/xxx.jpg")
    private String brandPic;

    @ApiModelProperty(value = "是否推荐该品牌", example = "false")
    private Boolean brandRecommend;

    @ApiModelProperty(value = "排序字段", example = "10")
    private Integer sort;


}
