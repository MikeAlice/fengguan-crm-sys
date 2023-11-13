package com.zeroone.star.systemindex.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.j1.systemindex.CustomerStatisticsVO;
import com.zeroone.star.systemindex.entity.CstCustomer;
import io.swagger.models.auth.In;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;


/**
 * <p>
 * 我的客户统计信息Mapper 接口
 * </p>
 *
 * @author accept_self
 *
 */
@Mapper
public interface CstCustomerMapper extends BaseMapper<CstCustomer> {


    List<CustomerStatisticsVO> countCustomerSource(@Param("userId") Integer userId);

    List<CustomerStatisticsVO> countCustomerGrade(@Param("userId") Integer userId);

    List<CustomerStatisticsVO> countCustomerIndustry(@Param("userId") Integer userId);
}
