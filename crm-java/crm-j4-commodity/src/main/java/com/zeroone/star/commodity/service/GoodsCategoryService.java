package com.zeroone.star.commodity.service;

import com.zeroone.star.commodity.entity.FlyGoodsCategory;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.AddGoodsCategoryDTO;
import com.zeroone.star.project.dto.j4.commodity.CategoryNameTreeDTO;
import com.zeroone.star.project.dto.j4.commodity.UpdateGoodsCategoryDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author 张二发
 */
public interface GoodsCategoryService {
    /**
     * 新增商品分类
     * @param goodsCategoryDTO 商品分类
     * @return 是否成功，如果失败，返回错误信息
     */
    JsonVO<Boolean> saveGoodsCategory(AddGoodsCategoryDTO goodsCategoryDTO);

    /**
     * 删除商品分类
     * @param goodsCategoryId 商品分类id
     * @return 是否成功，如果失败，返回错误信息
     */
    JsonVO<Boolean> removeGoodsCategory(int goodsCategoryId);

    /**
     * 修改商品分类
     * @param goodsCategoryDTO 商品分类
     * @return 是否成功，如果失败，返回错误信息
     */
    JsonVO<Boolean> modifyGoodsCategory(UpdateGoodsCategoryDTO goodsCategoryDTO);

    /**
     * 获取指定ID的商品分类
     */
    UpdateGoodsCategoryDTO getGoodsCategory(int goodsCategoryId);

    /**
     * 获取商品分类名称结构树
     */
    List<CategoryNameTreeDTO> listCategoryNameTree();

    /**
     * 获取商品分类列表
     * @return 商品分类列表
     */
    PageDTO<FlyGoodsCategory> listGoodsCategory(int pageNum, int pageSize);
}
