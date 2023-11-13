package com.zeroone.star.purchasemanagement.modules.contract.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j2.purchasemanagement.PosContractFileDTO;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractFileEntity;
import com.zeroone.star.purchasemanagement.modules.contract.mapper.PosContractFileMapper;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractFileService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 采购合同附件 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Service
public class PosContractFileServiceImpl extends ServiceImpl<PosContractFileMapper, PosContractFileEntity> implements PosContractFileService {

    /**
     * 添加合同附件
     *
     * @param posContractFileDTO
     * @return
     */
    @Override
    public Void addPosContractFile(PosContractFileDTO posContractFileDTO) {
        return null;
    }
}
