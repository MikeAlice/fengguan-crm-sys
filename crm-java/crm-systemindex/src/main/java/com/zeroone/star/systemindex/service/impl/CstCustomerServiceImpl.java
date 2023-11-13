package com.zeroone.star.systemindex.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.j1.systemindex.CustomerStatisticsVO;
import com.zeroone.star.systemindex.entity.CstCustomer;
import com.zeroone.star.systemindex.service.CstCustomerService;
import com.zeroone.star.systemindex.mapper.CstCustomerMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 我的客户统计信息 服务实现类
 * </p>
 *
 * @author accept_self
 *
 */
@Service
public class CstCustomerServiceImpl extends ServiceImpl<CstCustomerMapper, CstCustomer>
implements CstCustomerService{

    @Resource
    private CstCustomerMapper cstCustomerMapper;

    @Override
    public CustomerStatisticsVO countCustomerNumber(Integer userId) {

        QueryWrapper<CstCustomer> qw=new QueryWrapper<>();
        qw.eq("owner_user_id",userId);
        Long count = baseMapper.selectCount(qw);
        CustomerStatisticsVO customerStatisticsVO=new CustomerStatisticsVO();
        customerStatisticsVO.setStatisticsNumber(count.intValue());
        customerStatisticsVO.setStatisticsName("我的客户总数量");

        return customerStatisticsVO;
    }

    @Override
    public List<CustomerStatisticsVO> countCustomerSource(Integer userId) {

       return cstCustomerMapper.countCustomerSource(userId);


    }

    @Override
    public List<CustomerStatisticsVO> countCustomerGrade(Integer userId) {
        return cstCustomerMapper.countCustomerGrade(userId);
    }

    @Override
    public List<CustomerStatisticsVO> countCustomerIndustry(Integer userId) {
        return cstCustomerMapper.countCustomerIndustry(userId);
    }

}
