package com.zeroone.star.project.j1.systemindex;

import com.zeroone.star.project.dto.j1.systemindex.BusinessStatisticsDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemindex.BusinessStatisticsVO;

import java.util.List;

/**
 * 商家统计信息接口
 */
public interface BusinessStatisticsApis {

    /**
     * 统计商机数量
     * @return
     */
    JsonVO<BusinessStatisticsVO> countBusinessNumber() throws Exception;

    /**
     * 根据商机销售状态分类统计商机数量
     * @return
     */
    JsonVO<List<BusinessStatisticsVO>> countBusinessSalestage();

    /**
     * 根据商机预计销售额统计商机数量
     * @param businessStatisticsDTO
     * @return
     */
    JsonVO<List<BusinessStatisticsVO>> countBusinessMoney(BusinessStatisticsDTO businessStatisticsDTO);

    /**
     *根据商机预计成功率统计商机数量
     * @param businessStatisticsDTO
     * @return
     */
    JsonVO<List<BusinessStatisticsVO>> countBusinessSuccessRate(BusinessStatisticsDTO businessStatisticsDTO);
}
