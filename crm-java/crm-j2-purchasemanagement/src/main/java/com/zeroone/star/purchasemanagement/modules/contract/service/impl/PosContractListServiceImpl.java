package com.zeroone.star.purchasemanagement.modules.contract.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListPageQuery;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractListPageVO;
import com.zeroone.star.purchasemanagement.common.utils.ConvertUtil;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractListEntity;
import com.zeroone.star.purchasemanagement.modules.contract.excel.ContractDetailExcel;
import com.zeroone.star.purchasemanagement.modules.contract.mapper.PosContractListMapper;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractListService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 采购订单商品表 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Service
public class PosContractListServiceImpl extends ServiceImpl<PosContractListMapper, PosContractListEntity> implements PosContractListService {

    @Override
    public GetContractListPageVO getContractListPage(GetContractListPageQuery query) {
        // 获取明细合计信息
        GetContractListPageVO.TotalStatistic totalStatistic = baseMapper.getTotalStatistic();
        // 构建分页对象
        Page<PosContractListEntity> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 分页查询采购明细列表
        List<GetContractListPageVO.ContractListVO> list = baseMapper.getContractListPage(page, query);
        // 构建 PageDTO
        PageDTO<GetContractListPageVO.ContractListVO> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex(page.getCurrent());
        pageDTO.setPages(page.getPages());
        pageDTO.setPageSize(page.getSize());
        pageDTO.setRows(list);
        pageDTO.setTotal((long) list.size());
        // 构建 VO 并返回
        GetContractListPageVO result = ConvertUtil.sourceToTarget(pageDTO, GetContractListPageVO.class);
        result.setTotalStatistic(totalStatistic);
        return result;
    }

    @Override
    public List<ContractDetailExcel> getContractDetailExcelListByIds(List<Integer> contractDetailIdList) {
        return baseMapper.getContractDetailExcelListByIds(contractDetailIdList);
    }

}
