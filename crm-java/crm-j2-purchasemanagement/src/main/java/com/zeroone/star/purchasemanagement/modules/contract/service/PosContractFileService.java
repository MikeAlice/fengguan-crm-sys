package com.zeroone.star.purchasemanagement.modules.contract.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j2.purchasemanagement.PosContractFileDTO;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractFileEntity;

/**
 * <p>
 * 采购合同附件 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
public interface PosContractFileService extends IService<PosContractFileEntity> {

    /**
     * 修改合同基本信息
     * @param posContractFileDTO
     */
    Void addPosContractFile(PosContractFileDTO posContractFileDTO);

}
