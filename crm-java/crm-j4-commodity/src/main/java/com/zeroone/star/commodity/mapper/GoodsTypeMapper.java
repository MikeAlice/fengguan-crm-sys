package com.zeroone.star.commodity.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoodsAttr;
import com.zeroone.star.project.dto.j4.commodity.SimpleTypeInfoDTO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;
/**
 * @author Ak5ma1
 */
@Mapper
public interface GoodsTypeMapper extends BaseMapper<SimpleTypeInfoDTO> {
    public SimpleTypeInfoDTO findSimpleType(int id);

    public List<Integer> findAllIds();

    public List<String> findAllTags(int id);

    public List<FlyGoodsAttr> findPages(Page page);
}
