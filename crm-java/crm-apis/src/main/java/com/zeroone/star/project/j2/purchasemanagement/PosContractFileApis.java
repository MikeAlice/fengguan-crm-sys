package com.zeroone.star.project.j2.purchasemanagement;

import com.zeroone.star.project.dto.j2.purchasemanagement.PosContractFileDTO;
import com.zeroone.star.project.vo.JsonVO;
/**
 * 合同附件Api定义接口
 *
 */
public interface PosContractFileApis {
    /**
     * 添加合同附件
     * @param posContractFileDTO
     * @return
     */
    JsonVO<Void> addPosContractFile(PosContractFileDTO posContractFileDTO);
}
