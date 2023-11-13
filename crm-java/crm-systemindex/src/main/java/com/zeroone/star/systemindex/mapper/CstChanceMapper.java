package com.zeroone.star.systemindex.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.j1.systemindex.BusinessStatisticsVO;
import com.zeroone.star.systemindex.entity.CstChance;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;


/**
 * <p>
 * 我的商机统计信息Mapper 接口
 * </p>
 *
 * @author accept_self
 *
 */
@Mapper
public interface CstChanceMapper extends BaseMapper<CstChance> {

    List<BusinessStatisticsVO> countBusinessSalestage(@Param("userId") Integer userId);
}
