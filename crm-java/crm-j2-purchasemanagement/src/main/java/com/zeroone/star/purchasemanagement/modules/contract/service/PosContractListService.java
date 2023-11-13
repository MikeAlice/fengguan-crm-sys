package com.zeroone.star.purchasemanagement.modules.contract.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListPageQuery;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractListPageVO;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractListEntity;
import com.zeroone.star.purchasemanagement.modules.contract.excel.ContractDetailExcel;

import java.util.List;

/**
 * <p>
 * 采购订单商品表 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
public interface PosContractListService extends IService<PosContractListEntity> {

    /**
     * 获取明细列表（分页+条件）
     *
     * @param query 查询参数
     * @return 明细列表分页模型
     */
    GetContractListPageVO getContractListPage(GetContractListPageQuery query);

    /**
     * 根据list_id集合获取明细excel实体列表
     * @param contractDetailIdList 指定的list_id集合
     * @return excel实体列表
     */
    List<ContractDetailExcel> getContractDetailExcelListByIds(List<Integer> contractDetailIdList);
}
