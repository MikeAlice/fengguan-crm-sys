package com.zeroone.star.systemindex.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.j1.systemindex.CustomerStatisticsVO;
import com.zeroone.star.systemindex.entity.CstCustomer;

import java.util.List;

public interface CstCustomerService extends IService<CstCustomer> {


    CustomerStatisticsVO countCustomerNumber(Integer userId);


    List<CustomerStatisticsVO> countCustomerSource(Integer userId);

    List<CustomerStatisticsVO>  countCustomerGrade(Integer userId);

    List<CustomerStatisticsVO> countCustomerIndustry(Integer userId);
}
