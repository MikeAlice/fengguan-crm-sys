package com.zeroone.star.systemindex.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j1.systemindex.BusinessStatisticsDTO;
import com.zeroone.star.project.vo.j1.systemindex.BusinessStatisticsVO;
import com.zeroone.star.systemindex.entity.CstChance;

import java.util.List;


public interface CstChanceService extends IService<CstChance> {

    BusinessStatisticsVO countBusinessNumber(Integer userId);

    List<BusinessStatisticsVO> countBusinessSalestage(Integer userId);

    List<BusinessStatisticsVO> countBusinessMoney(Integer userId, BusinessStatisticsDTO businessStatisticsDTO);

    List<BusinessStatisticsVO> countBusinessSuccessRate(Integer userId, BusinessStatisticsDTO businessStatisticsDTO);
}
