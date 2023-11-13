package com.zeroone.star.systemindex.controller;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.systemindex.CustomerStatisticsApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemindex.CustomerStatisticsVO;
import com.zeroone.star.systemindex.service.CstCustomerService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 我的客户统计信息 Controller
 * </p>
 *
 * @author accept_self
 */
@RestController
@RequestMapping("/sysindex")
@Api(tags = "我的客户统计信息")
public class CustomerStatisticsController implements CustomerStatisticsApis {

    @Resource
    private CstCustomerService cstCustomerService;

    @Resource
    private UserHolder userHolder;
    @ApiOperation("统计客户数量")
    @GetMapping("/count-customer-number")
    @Override
    public JsonVO<CustomerStatisticsVO> countCustomerNumber()  {

        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();
            return JsonVO.success(cstCustomerService.countCustomerNumber(userId));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    @ApiOperation("根据客户来源统计数量")
    @GetMapping("/count-customer-source")
    @Override
    public JsonVO<List<CustomerStatisticsVO>> countCustomerSource() {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();
            return JsonVO.success(cstCustomerService.countCustomerSource(userId));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @ApiOperation("根据客户等级统计数量")
    @GetMapping("/count-customer-grade")
    @Override
    public JsonVO<List<CustomerStatisticsVO>> countCustomerGrade() {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();
            return JsonVO.success(cstCustomerService.countCustomerGrade(userId));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @ApiOperation("根据客户行业统计数量")
    @GetMapping("/count-customer-industry")
    @Override
    public JsonVO<List<CustomerStatisticsVO>> countCustomerIndustry() {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();
            return JsonVO.success(cstCustomerService.countCustomerIndustry(userId));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
