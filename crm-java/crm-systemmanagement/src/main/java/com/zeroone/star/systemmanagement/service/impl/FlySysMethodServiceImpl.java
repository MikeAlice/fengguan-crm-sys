package com.zeroone.star.systemmanagement.service.impl;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysAddMethodDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMethodDTO;
import com.zeroone.star.project.query.j1.systemmanagement.GetMethodListQuery;
import com.zeroone.star.project.vo.j1.systemmanagement.MethodListVO;
import com.zeroone.star.systemmanagement.entity.FlySysMethod;
import com.zeroone.star.systemmanagement.mapper.FlySysMethodMapper;
import com.zeroone.star.systemmanagement.service.IFlySysMethodService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsMethodStruct{
    FlySysMethod methodDtoToDo(FlySysMethodDTO dto);
    FlySysMethod addMethodDtoToDo(FlySysAddMethodDTO addDto);
}

/**
 * <p>
 * 系统方法 服务实现类
 * </p>
 *
 * @author 点点
 * @since 2023-11-01
 */
@Service
public class FlySysMethodServiceImpl extends ServiceImpl<FlySysMethodMapper, FlySysMethod> implements IFlySysMethodService {
    @Resource
    MsMethodStruct msMethodStruct;
    @Override
    public boolean saveMethod(FlySysAddMethodDTO flySysMethodDTO) {
        //不传id，不作判断
        //2. 添加权限
        FlySysMethod flySysMethod = msMethodStruct.addMethodDtoToDo(flySysMethodDTO);
        return save(flySysMethod);
    }

    @Override
    public boolean updateMethod(FlySysMethodDTO flySysMethodDTO) {
        //1.判断记录是否存在
        //1.1获取权限id
        Integer id = flySysMethodDTO.getId();
        //1.2 id为空或者id不存在
        if (id==null||lambdaQuery().eq(FlySysMethod::getId, id).one()==null){
            System.out.println("权限不存在");
            return false;
        }
        //2. 修改权限
        FlySysMethod flySysMethod = msMethodStruct.methodDtoToDo(flySysMethodDTO);
        return updateById(flySysMethod);
    }

    /**
     * 获取权限列表
     * @param getMethodListQuery 获取权限列表查询参数
     * @return 权限列表分页vo模型
     */
    @Override
    public PageDTO<MethodListVO> getMethodList(GetMethodListQuery getMethodListQuery) {
        // 分页查询系统方法列表
        Page<FlySysMethod> page = lambdaQuery()
                // 菜单ID不为0 -> 根据菜单ID查询
                .eq(getMethodListQuery.getMenuId() != 0, FlySysMethod::getMenuID, getMethodListQuery.getMenuId())
                // 关键字不为空 -> 根据关键字模糊查询
                .like(StrUtil.isNotEmpty(getMethodListQuery.getKeywords()), FlySysMethod::getName, getMethodListQuery.getKeywords())
                // 按sort升序
                .orderByAsc(FlySysMethod::getSort)
                // 根据分页参数分页查询
                .page(new Page<>(getMethodListQuery.getPageIndex(), getMethodListQuery.getPageSize()));
        // 转化vo，构造分页模型并返回
        return PageDTO.create(page, MethodListVO.class);
    }
}
