package com.zeroone.star.commodity.service;

import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.RecommendDTO;
import com.zeroone.star.project.dto.j4.commodity.ShelfGoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.validation.ContentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * @author 骇客老薛
 * @date 2023/10/24 20:00
 * com.zeroone.star.commodity.service
 */
public interface GoodsService {

    /**
     * 通过Id查询
     *
     * @param goodsId 唯一id
     * @return 查询结果
     */
    JsonVO<GoodsDTO> getGoodsDetailsById(Integer goodsId);


    /**
     * 发布商品
     * @param goodsDTO
     * @return
     */
    JsonVO<Boolean> addGoods(GoodsDTO goodsDTO);


    JsonVO<Boolean> isRecommend(RecommendDTO recommendDTO);

    JsonVO<Boolean> modifyGoodsState(ShelfGoodsDTO shelfGoodsDTO);

    JsonVO<List<String>> getGoodsNames();

    JsonVO<Boolean> removeGoods(List<Integer> deleteGoodsIdList);
}
