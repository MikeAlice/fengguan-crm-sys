package com.zeroone.star.project.j4.commodity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.*;
import com.zeroone.star.project.query.j4.commodity.GoodsCategoryQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 商品分类相关接口
 * @author 张二发
 */
public interface GoodsCategoryApis {
    /**
     * 添加商品分类
     * @param goodsCategoryDTO 商品分类信息
     * @return 是否添加成功
     */
    JsonVO<Boolean> addGoodsCategory(AddGoodsCategoryDTO goodsCategoryDTO);

    /**
     * 删除商品分类
     * @param goodsCategoryId 商品分类id
     * @return 是否删除成功
     */
    JsonVO<Boolean> removeGoodsCategory(int goodsCategoryId);

    /**
     * 修改商品分类
     * @param goodsCategoryDTO 商品分类信息
     * goodsCategoryId 商品分类id
     */
    JsonVO<Boolean> modifyGoodsCategory(UpdateGoodsCategoryDTO goodsCategoryDTO);

    /**
     * 获取商品分类
     * @param goodsCategoryId 商品分类id
     * @return 商品分类信息
     */
    JsonVO<UpdateGoodsCategoryDTO> queryGoodsCategory(int goodsCategoryId);

    /**
     * 分页查询商品分类名称结构树
     * @return
     */
    public JsonVO<List<CategoryNameTreeDTO>> queryGoodsCategoryNameTree();

}
