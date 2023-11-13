package com.zeroone.star.systemmanagement.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysConfigDTO;
import com.zeroone.star.project.query.j1.systemmanagement.FlySysConfigQuery;
import com.zeroone.star.systemmanagement.entity.FlySysConfig;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 系统配置表 服务类
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
public interface IFlySysConfigService extends IService<FlySysConfig> {
    //获取系统参数
    PageDTO<FlySysConfigDTO> listAll(FlySysConfigQuery query);

    //更新系统参数
    String updateSysParam(List<FlySysConfigDTO> dtos);

}
