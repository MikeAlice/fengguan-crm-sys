package com.zeroone.star.systemmanagement.service;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysAddMethodDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMethodDTO;
import com.zeroone.star.project.query.j1.systemmanagement.GetMethodListQuery;
import com.zeroone.star.project.vo.j1.systemmanagement.MethodListVO;
import com.zeroone.star.systemmanagement.entity.FlySysMethod;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 系统方法 服务类
 * </p>
 *
 * @author 点点
 * @since 2023-11-01
 */
public interface IFlySysMethodService extends IService<FlySysMethod> {
    boolean saveMethod(FlySysAddMethodDTO flySysMethodDTO);

    boolean updateMethod(FlySysMethodDTO flySysMethodDTO);

    /**
     * 获取权限列表
     * @param getMethodListQuery 获取权限列表查询参数
     * @return 权限列表分页vo模型
     */
    PageDTO<MethodListVO> getMethodList(GetMethodListQuery getMethodListQuery);

}
