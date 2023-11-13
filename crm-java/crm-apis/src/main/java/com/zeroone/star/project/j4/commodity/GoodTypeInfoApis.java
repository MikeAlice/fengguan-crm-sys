package com.zeroone.star.project.j4.commodity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.AddNewTypeDTO;
import com.zeroone.star.project.dto.j4.commodity.ModifyTypeDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j4.commodity.GoodsTypeIdQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.commodity.DetailedTypeVO;
import com.zeroone.star.project.vo.j4.commodity.SimpleTypeVO;
import org.springframework.validation.BindingResult;

import javax.validation.Valid;

/**
 * 商品类型相关接口
 * @author Ak5ma1
 */
public interface GoodTypeInfoApis {
    /**
     * @author Ak5ma1
     * @description 获取商品简单类型列表 (分页)
     * pageQuery 分页参数
     * @return JsonVO<PageDTO < SimpleTypeInfoDTO>>
     */
    JsonVO<PageDTO<SimpleTypeVO>> findSimpleType(@Valid PageQuery pageQuery,BindingResult result);
    /**
     * @author Ak5ma1
     * @description 获取查询详情页面
     * @param goodsTypeIdQuery 商品类型对应id
     * @return JsonVO<DetailedTypeInfoDTO>
     */
    JsonVO<DetailedTypeVO> findDetailedType(@Valid GoodsTypeIdQuery goodsTypeIdQuery, BindingResult result);
    /**
     * @author Ak5ma1
     * @description 修改查询详情页面
     * @param modifyTypeDTO 商品类型详细信息、删除列表
     * @return JsonVO<Boolean>
     */
    JsonVO<Boolean> modifyDetailedType(@Valid ModifyTypeDTO modifyTypeDTO,BindingResult result);
    /**
     * @author Ak5ma1
     * @description 修改查询详情页面
     * @param goodsTypeIdQuery 商品类型对应id
     * @return JsonVO<Boolean>
     */
    JsonVO<String> deleteType(@Valid GoodsTypeIdQuery goodsTypeIdQuery, BindingResult result);

    JsonVO<Boolean> addDetailedType(@Valid AddNewTypeDTO addNewTypeDTO, BindingResult result);

//    JsonVO<Boolean> deleteGoodAttrValue(int attrValueId);
}
