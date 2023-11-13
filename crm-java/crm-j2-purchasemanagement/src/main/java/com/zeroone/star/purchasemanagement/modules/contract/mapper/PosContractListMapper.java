package com.zeroone.star.purchasemanagement.modules.contract.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListPageQuery;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractListPageVO;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractListEntity;
import com.zeroone.star.purchasemanagement.modules.contract.excel.ContractDetailExcel;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 * 采购订单商品表 Mapper 接口
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Mapper
public interface PosContractListMapper extends BaseMapper<PosContractListEntity> {
    GetContractListPageVO.TotalStatistic getTotalStatistic();

    List<GetContractListPageVO.ContractListVO> getContractListPage(Page<PosContractListEntity> page, @Param("param")GetContractListPageQuery query);

    List<ContractDetailExcel> getContractDetailExcelListByIds(List<Integer> contractDetailIdList);
}
