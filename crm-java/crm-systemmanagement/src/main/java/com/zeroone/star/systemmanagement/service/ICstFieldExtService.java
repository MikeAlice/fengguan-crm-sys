package com.zeroone.star.systemmanagement.service;

import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtDTO;
import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 客户字段扩展表 服务类
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
public interface ICstFieldExtService extends IService<CstFieldExt> {
    String addCstFieldExt(CstFieldExtDTO dto);
    boolean removeByIdExceptSysMsg(Integer id);
    boolean batchRemoveByIds(List<Integer> ids);
}
