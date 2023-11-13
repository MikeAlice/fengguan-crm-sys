package com.zeroone.star.project.j4.commodity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.SpecDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j4.commodity.CommoditySpecQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 *     描述：商品规格
 * </p>
 *
 * @author Tezz
 * @version 1.0.0
 * @date 2023-10-21
 */
public interface CommoditySpecApis {



    /**
     * 修改商品规格
     * @param specDTO
     * @return 修改成功结果为ture
     */
    JsonVO<Boolean> modifyData(SpecDTO specDTO);

    /**
     * 删除商品规格
     * @param specId
     * @return 删除成功结果为ture
     */
    JsonVO<Boolean> deleteData(int specId);
    /**
     * 添加商品规格
     * @param specDTO
     * @return 新增成功结果为ture
     */
    JsonVO<Boolean> addData(SpecDTO specDTO);

    /**
     * @author zhairenhao
     * @description 获取商品规格列表(条件+分页)
     * @param query
     * @return JsonVO<PageDTO < SpecDTO>>
     */
    JsonVO<PageDTO<SpecDTO>> getCommoditySpec(CommoditySpecQuery query);


}
