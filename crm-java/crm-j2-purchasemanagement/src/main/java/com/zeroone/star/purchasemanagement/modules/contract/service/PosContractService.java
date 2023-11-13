package com.zeroone.star.purchasemanagement.modules.contract.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j2.purchasemanagement.AddContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ContractSelectDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ModifyContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.SelectContractDTO;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListWithPageConditionQuery;
import com.zeroone.star.project.vo.j2.purchasemanagement.*;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractEntity;

import java.util.List;

/**
 * <p>
 * 采购合同 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
public interface PosContractService extends IService<PosContractEntity> {

    /**
     * 获取合同列表 (分页+条件)
     * @param getContractListWithPageConditionQuery 获取合同列表查询参数
     * @return 合同列表分页模型
     */
    GetContractListWithPageConditionVO getContractListWithPageCondition(GetContractListWithPageConditionQuery getContractListWithPageConditionQuery);

    /**
     * 获取合同详情
     * @param contractId 合同ID
     * @return 合同详情vo模型
     */
    GetContractDetailVO getContractDetail(Integer contractId);

    /**
     * 获取合同清单
     * @param contractId 合同ID
     * @return 合同清单vo模型
     */
    GetContractInventoryVO getContractInventory(Integer contractId);


    /**
     * 修改合同基本信息
     * @param modifyContractDTO
     */
    void updateContract(ModifyContractDTO modifyContractDTO);


    /**
     * 添加合同
     * @param addContractDTO
     */
    void saveContract(AddContractDTO addContractDTO);

    /**
     * 获取合同唯一编号
     * @return
     */
    GetContractNoVO getContractNo();

    /**
     * 导出合同
     * @param contractIds
     * @return
     */
    ExportContractVO exportContract(List<Integer> contractIds) throws Exception;

    ContractSelectDTO selectContract(SelectContractDTO dto);
}
