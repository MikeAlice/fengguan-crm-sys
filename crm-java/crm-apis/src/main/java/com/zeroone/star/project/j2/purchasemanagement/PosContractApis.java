package com.zeroone.star.project.j2.purchasemanagement;

import com.zeroone.star.project.dto.j2.purchasemanagement.AddContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ContractSelectDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ModifyContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.SelectContractDTO;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListWithPageConditionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.*;

import java.text.ParseException;
import java.util.List;

/**
 * 采购订单API定义接口
 *
 * @author j2
 * @since 2023/10/29
 */
public interface PosContractApis {
    /**
     * 获取合同列表 (分页+条件)
     * @param getContractListWithPageConditionQuery 获取合同列表查询参数
     * @return 合同列表分页模型
     */
    JsonVO<GetContractListWithPageConditionVO> getContractListWithPageCondition(GetContractListWithPageConditionQuery getContractListWithPageConditionQuery);

    /**
     * 获取合同详情
     * @param contractId 合同ID
     * @return 合同详情vo模型
     */
    JsonVO<GetContractDetailVO> getContractDetail(Integer contractId);

    /**
     * 获取合同清单
     * @param contractId 合同ID
     * @return 合同清单vo模型
     */
    JsonVO<GetContractInventoryVO> getContractInventory(Integer contractId);

    /**
     * 修改采购合同的基本信息
     * @param modifyContractDTO
     * @return
     */
    JsonVO<String> modifyContract(ModifyContractDTO modifyContractDTO);

    /**
     * 添加采购合同
     * @param addContractDTO
     * @return
     */
    JsonVO<String> addContract(AddContractDTO addContractDTO) throws ParseException;

    /**
     * 获得合同唯一编号
     * @return
     */
    JsonVO<GetContractNoVO> getContractNo();

    JsonVO<ExportContractVO> exportContract(List<Integer> contractIds) throws Exception;

    JsonVO<ContractSelectDTO> selectContractPay(SelectContractDTO dto);
}
