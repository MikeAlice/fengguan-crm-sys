package com.zeroone.star.project.j4.commodity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.RecommendDTO;
import com.zeroone.star.project.dto.j4.commodity.ShelfGoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.maintenance.GoodsListDTO;
import com.zeroone.star.project.query.j4.commodity.GoodsQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author zhairenhao
 * @date 2023/10/22 22:41
 * @description 商品相关接口
 */
public interface GoodsApis {
    /**
     * @param query
     * @return JsonVO<PageDTO < GoodsSkuDTO>>
     * @author zhairenhao
     * @description 获取商品列表 (分页+条件)
     */
    JsonVO<PageDTO<GoodsListDTO>> listGoodsByPages(GoodsQuery query);

    /**
     * @param goodsDTO
     * @return JsonVO<Boolean>
     * @author zhairenhao
     * @description 修改商品
     */
    JsonVO<Boolean> updateGoodsById(GoodsDTO goodsDTO);

    /**
     * 获取商品详细内容
     * @param goodsId
     * @return
     */
    JsonVO<GoodsDTO> getGoodsDetails(Integer goodsId);

    /**
     * 推荐/取消推荐(支持批量操作)
     * @param
     * @return
     */
    JsonVO<Boolean> isRecommend(RecommendDTO recommendDTO);

    /**
     * 上架/下架商品(支持批量操作)
     * @param shelfGoodsDTO
     * @return
     */
    JsonVO<Boolean> goodsState(ShelfGoodsDTO shelfGoodsDTO);

    /**
     * 删除商品
     * @param deleteGoodsIdList
     * @return
     */
    JsonVO<Boolean> deleteGoods(List<Integer> deleteGoodsIdList);

    /**
     * 获取商品类型名称列表 (用于输入表单下拉列表)
     * @param
     * @return
     */
    JsonVO<List<String>> getGoodsNames();

    /**
     * 发布商品
     * @param goodsDTO
     * @return
     */
    JsonVO<Boolean> addGoods(GoodsDTO goodsDTO);
}
