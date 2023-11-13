package com.zeroone.star.systemmanagement.mapper;

import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 客户字段扩展表 Mapper 接口
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@Mapper
public interface CstFieldExtMapper extends BaseMapper<CstFieldExt> {
    Integer selectIsSystemById(Integer id);

}
