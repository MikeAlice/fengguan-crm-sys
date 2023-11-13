package com.zeroone.star.project.vo.j4.commodity;


import io.swagger.annotations.ApiModelProperty;

import java.util.List;

/**
 * 展示给前端数据的对象
 */
public class BrandVO {



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
