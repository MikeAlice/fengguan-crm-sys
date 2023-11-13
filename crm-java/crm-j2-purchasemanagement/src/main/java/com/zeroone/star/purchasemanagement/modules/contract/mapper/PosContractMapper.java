package com.zeroone.star.purchasemanagement.modules.contract.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListWithPageConditionQuery;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractDetailVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractListWithPageConditionVO;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractEntity;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.math.BigDecimal;
import java.util.List;

/**
 * <p>
 * 采购合同 Mapper 接口
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Mapper
public interface PosContractMapper extends BaseMapper<PosContractEntity> {

    GetContractListWithPageConditionVO.ContractMoneyStatistic getContractMoneyStatistic();

    List<GetContractListWithPageConditionVO.ContractVO> getContractListWithPage(Page<PosContractEntity> page, @Param("param") GetContractListWithPageConditionQuery getContractListWithPageConditionQuery);

    GetContractDetailVO getContractBaseInfoById(@Param("contractId") Integer contractId);

    GetContractDetailVO.TotalStatistic getContractDetailNumMoneyStatistic(@Param("contractId") Integer contractId);

    BigDecimal getPayRecordTotalMoney(@Param("contractId") Integer contractId);

    BigDecimal getInvoiceTotalMoney(@Param("contractId") Integer contractId);

    List<GetContractDetailVO.PayRecord> getPayRecordListByContractId(@Param("contractId") Integer contractId);

    List<GetContractDetailVO.InvoiceRecord> getInvoiceRecordListByContractId(@Param("contractId") Integer contractId);
}
