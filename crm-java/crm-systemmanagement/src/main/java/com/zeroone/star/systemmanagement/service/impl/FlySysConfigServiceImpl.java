package com.zeroone.star.systemmanagement.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysConfigDTO;
import com.zeroone.star.project.query.j1.systemmanagement.FlySysConfigQuery;
import com.zeroone.star.systemmanagement.entity.FlySysConfig;
import com.zeroone.star.systemmanagement.mapper.FlySysConfigMapper;
import com.zeroone.star.systemmanagement.service.IFlySysConfigService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsFlySysConfigStruct{
    FlySysConfigDTO fscToFlcDto(FlySysConfig flySysConfig);

    FlySysConfig flcDTOtoFsc(FlySysConfigDTO flySysConfigDTO);
}


/**
 * <p>
 * 系统配置表 服务实现类
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@Service
public class FlySysConfigServiceImpl extends ServiceImpl<FlySysConfigMapper, FlySysConfig> implements IFlySysConfigService {

    @Resource
    MsFlySysConfigStruct msFlySysConfigStruct;

    /**
     * 查询所有，这个query只提供了分页数据，没有其他的条件
     * @param query
     * @return
     */

    @Override
    public PageDTO<FlySysConfigDTO> listAll(FlySysConfigQuery query) {
        Page<FlySysConfig> flySysConfigPage = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<FlySysConfig> result = baseMapper.selectPage(flySysConfigPage, null);
        return PageDTO.create(result,src -> msFlySysConfigStruct.fscToFlcDto(src));
    }

    /**
     * 通过前端传入的id来批量更新数据
     * @param
     * @return
     */
    @Override
    public String updateSysParam(List<FlySysConfigDTO> dtos) {
        for (FlySysConfigDTO dto : dtos){
            baseMapper.updateById(msFlySysConfigStruct.flcDTOtoFsc(dto));
        }
        return "更新成功";
    }
}
