package com.zeroone.star.systemindex.controller;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j1.systemindex.BusinessStatisticsDTO;
import com.zeroone.star.project.j1.systemindex.BusinessStatisticsApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemindex.BusinessStatisticsVO;
import com.zeroone.star.systemindex.service.CstChanceService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 我的商机统计信息 Controller
 * </p>
 *
 * @author accept_self
 */
@RestController
@RequestMapping("/sysindex")
@Api(tags = "我的商机统计信息")
public class BusinessStatisticsController implements BusinessStatisticsApis {

    @Resource
    private CstChanceService cstChanceService;

    @Resource
    private UserHolder userHolder;

    @ApiOperation("统计商机数量")
    @GetMapping("/count-business-number")
    @Override
    public JsonVO<BusinessStatisticsVO> countBusinessNumber() {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();

            return JsonVO.success(cstChanceService.countBusinessNumber(userId));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    @ApiOperation("根据商机销售状态分类统计商机数量")
    @GetMapping("/count-business-salestage")
    @Override
    public JsonVO<List<BusinessStatisticsVO>> countBusinessSalestage() {

        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();

            return JsonVO.success(cstChanceService.countBusinessSalestage(userId));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @ApiOperation("根据商机预计销售额统计商机数量")
    @GetMapping("/count-business-money")
    @Override
    public JsonVO<List<BusinessStatisticsVO>> countBusinessMoney(BusinessStatisticsDTO businessStatisticsDTO) {
        try {
            if(BeanUtil.isEmpty(businessStatisticsDTO) || BeanUtil.isEmpty(businessStatisticsDTO.getFirstData()) || BeanUtil.isEmpty(businessStatisticsDTO.getSecondData())){
                return JsonVO.create(null, 9999,"传入的数据不能为空");
            }
            if(businessStatisticsDTO.getFirstData()<0 || businessStatisticsDTO.getFirstData()>=businessStatisticsDTO.getSecondData()){
                return JsonVO.create(null, 9999,"传入的数据格不符合要求");
            }

            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();
            return JsonVO.success(cstChanceService.countBusinessMoney(userId,businessStatisticsDTO));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @ApiOperation("根据商机预计成功率统计商机数量")
    @GetMapping("/count-business-successrate")
    @Override
    public JsonVO<List<BusinessStatisticsVO>> countBusinessSuccessRate(BusinessStatisticsDTO businessStatisticsDTO) {
        try {
            if(BeanUtil.isEmpty(businessStatisticsDTO) || BeanUtil.isEmpty(businessStatisticsDTO.getFirstData()) || BeanUtil.isEmpty(businessStatisticsDTO.getSecondData())){
                return JsonVO.create(null, 9999,"传入的数据不能为空");
            }
            if(businessStatisticsDTO.getFirstData()>=businessStatisticsDTO.getSecondData() || businessStatisticsDTO.getFirstData()< 0 || businessStatisticsDTO.getSecondData()>100 ){
                return JsonVO.create(null, 9999,"传入的数据格不符合要求");
            }

            UserDTO currentUser = userHolder.getCurrentUser();
            if(BeanUtil.isEmpty(currentUser)){
                return  JsonVO.fail(null);
            }
            Integer userId = currentUser.getId();
            return JsonVO.success(cstChanceService.countBusinessSuccessRate(userId,businessStatisticsDTO));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
