package com.zeroone.star.systemindex.service.impl;


import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j1.systemindex.BusinessStatisticsDTO;
import com.zeroone.star.project.vo.j1.systemindex.BusinessStatisticsVO;
import com.zeroone.star.systemindex.entity.CstChance;
import com.zeroone.star.systemindex.mapper.CstChanceMapper;
import com.zeroone.star.systemindex.service.CstChanceService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 我的商机统计信息 服务实现类
 * </p>
 *
 * @author accept_self
 *
 */
@Service
public class CstChanceServiceImpl extends ServiceImpl<CstChanceMapper, CstChance>
implements CstChanceService{

    @Resource
    private CstChanceMapper cstChanceMapper;
    @Override
    public BusinessStatisticsVO countBusinessNumber(Integer userId) {
        QueryWrapper<CstChance> qw=new QueryWrapper<>();
        qw.eq("userID",userId);
        Long count = baseMapper.selectCount(qw);
        BusinessStatisticsVO businessStatisticsVO=new BusinessStatisticsVO();
        businessStatisticsVO.setStatisticsNumber(count.intValue());
        businessStatisticsVO.setStatisticsName("我的商业机会总数量");
        return businessStatisticsVO;
    }

    @Override
    public List<BusinessStatisticsVO> countBusinessSalestage(Integer userId) {

        return cstChanceMapper.countBusinessSalestage(userId);
    }

    @Override
    public List<BusinessStatisticsVO> countBusinessMoney(Integer userId, BusinessStatisticsDTO businessStatisticsDTO) {

        List<BusinessStatisticsVO> bList=new ArrayList<>();
        QueryWrapper<CstChance> qw=new QueryWrapper<>();
        qw.eq("userID",userId);

        CstChance cstChance = baseMapper.selectOne(qw);
        if(BeanUtil.isEmpty(cstChance)){

            return bList;
        }
        //统计小于第一个传入数据的数量
        qw.lt("money",businessStatisticsDTO.getFirstData());
        Long count = baseMapper.selectCount(qw);
        BusinessStatisticsVO bv=new BusinessStatisticsVO();
        bv.setStatisticsName("金额小于"+businessStatisticsDTO.getFirstData()+"元");
        bv.setStatisticsNumber(count.intValue());
        bList.add(bv);
        //统计大于等于第一个传入数据，小于等于第二个传入数据的数量
        qw=new QueryWrapper<>();
        qw.eq("userID",userId);
        qw.ge("money",businessStatisticsDTO.getFirstData());
        qw.le("money",businessStatisticsDTO.getSecondData());
        count = baseMapper.selectCount(qw);
        bv=new BusinessStatisticsVO();
        bv.setStatisticsName("金额在"+businessStatisticsDTO.getFirstData()+"-"+businessStatisticsDTO.getSecondData()+"元之间");
        bv.setStatisticsNumber(count.intValue());
        bList.add(bv);
        //统计大于第二个传入数据的数量
        qw=new QueryWrapper<>();
        qw.eq("userID",userId);
        qw.gt("money",businessStatisticsDTO.getSecondData());
        count= baseMapper.selectCount(qw);
        bv=new BusinessStatisticsVO();
        bv.setStatisticsName("金额大于"+businessStatisticsDTO.getSecondData()+"元");
        bv.setStatisticsNumber(count.intValue());
        bList.add(bv);
        return bList;
    }

    @Override
    public List<BusinessStatisticsVO> countBusinessSuccessRate(Integer userId, BusinessStatisticsDTO businessStatisticsDTO) {
        List<BusinessStatisticsVO> bList=new ArrayList<>();
        QueryWrapper<CstChance> qw=new QueryWrapper<>();
        qw.eq("userID",userId);

        CstChance cstChance = baseMapper.selectOne(qw);
        if(BeanUtil.isEmpty(cstChance)){
            return bList;
        }

        //统计小于第一个传入数据的数量
        qw.lt("success_rate",businessStatisticsDTO.getFirstData());
        Long count = baseMapper.selectCount(qw);
        BusinessStatisticsVO bv=new BusinessStatisticsVO();
        bv.setStatisticsName("成功小于"+businessStatisticsDTO.getFirstData()+"%");
        bv.setStatisticsNumber(count.intValue());
        bList.add(bv);
        //统计大于等于第一个传入数据，小于等于第二个传入数据的数量
        qw=new QueryWrapper<>();
        qw.eq("userID",userId);
        qw.ge("success_rate",businessStatisticsDTO.getFirstData());
        qw.le("success_rate",businessStatisticsDTO.getSecondData());
        count = baseMapper.selectCount(qw);
        bv=new BusinessStatisticsVO();
        bv.setStatisticsName("成功率在"+businessStatisticsDTO.getFirstData()+"-"+businessStatisticsDTO.getSecondData()+"%之间");
        bv.setStatisticsNumber(count.intValue());
        bList.add(bv);
        //统计大于第二个传入数据的数量
        qw=new QueryWrapper<>();
        qw.eq("userID",userId);
        qw.gt("success_rate",businessStatisticsDTO.getSecondData());
        count= baseMapper.selectCount(qw);
        bv=new BusinessStatisticsVO();
        bv.setStatisticsName("成功率大于"+businessStatisticsDTO.getSecondData()+"%");
        bv.setStatisticsNumber(count.intValue());
        bList.add(bv);
        return bList;




    }
}
