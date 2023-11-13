package com.zeroone.star.project.j1.systemindex;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemindex.CustomerStatisticsVO;

import java.util.List;

/**
 * 客户统计信息接口
 */
public interface CustomerStatisticsApis {

    /**
     * 统计当前用户的 我的客户总数量
     * @return
     */
    JsonVO<CustomerStatisticsVO> countCustomerNumber() throws Exception;

    /**
     * 根据客户来源统计当前用户下各来源的客户数量
     * @return
     */
    JsonVO<List<CustomerStatisticsVO>> countCustomerSource() throws Exception;

    /**
     * 根据客户等级统计当前用户下各等级下的客户数量
     * @return
     */
    JsonVO<List<CustomerStatisticsVO>> countCustomerGrade() throws Exception;

    /**
     * 根据客户行业不同统计当前用户下各行业下的客户数量
     * @return
     */
    JsonVO<List<CustomerStatisticsVO>> countCustomerIndustry() throws Exception;

}
