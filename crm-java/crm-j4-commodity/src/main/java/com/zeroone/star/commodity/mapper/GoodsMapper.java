package com.zeroone.star.commodity.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.commodity.entity.FlyGoods;
import com.zeroone.star.project.dto.j4.commodity.validation.ContentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * @author 骇客老薛
 * @date 2023/10/25 23:01
 * com.zeroone.star.commodity.mapper
 */
@Mapper
public interface GoodsMapper extends BaseMapper<FlyGoods> {

    List<String> getGoodsNames();


    JsonVO<ContentDTO> getGoodsDetailsById(Integer goodsId);
}
