package com.zeroone.star.project.j2.purchasemanagement;

import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractListPageVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.ExportContractDetailVO;

import java.util.List;

/**
 * 采购明细API定义接口
 *
 * @author j2
 * @since 2023/10/29
 */
public interface PosContractListApis {
    /**
     * 获取明细列表（分页+条件）
     *
     * @param query 条件查询参数
     * @return 明细列表分页模型
     */
    JsonVO<GetContractListPageVO> getContractListPage(GetContractListPageQuery query);

    /**
     * 导出合同明细
     * @param contractDetailIdList 采购合同明细id集合
     * @return 导出合同明细excel表格文件地址vo
     */
    JsonVO<ExportContractDetailVO> exportContractDetail(List<Integer> contractDetailIdList) throws Exception;
}
