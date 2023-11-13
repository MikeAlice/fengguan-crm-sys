package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysConfigDTO;
import com.zeroone.star.project.query.j1.systemmanagement.FlySysConfigQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;


public interface FlySysConfigApis {
    /**
     * 获取系统参数
     * @param query  查询条件，这里没给定，查询全部
     * @return 查询到的数据
     */
    JsonVO<PageDTO<FlySysConfigDTO>> listAll(FlySysConfigQuery query);

    /**
     *更新系统参数 根据id更改
     * @param dtos 需要更改的对象
     * @return 返回提示信息
     */
    JsonVO<String> updateSysParam( List<FlySysConfigDTO> dtos);

}
