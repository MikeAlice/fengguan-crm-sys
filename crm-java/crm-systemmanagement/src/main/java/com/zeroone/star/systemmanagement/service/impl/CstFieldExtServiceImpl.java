package com.zeroone.star.systemmanagement.service.impl;

import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtDTO;
import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.zeroone.star.systemmanagement.mapper.CstFieldExtMapper;
import com.zeroone.star.systemmanagement.service.ICstFieldExtService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.aop.framework.AopContext;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;
@Mapper(componentModel = "spring")
interface MsCstFieldExtStruct{
    CstFieldExt cfeDtoToCfe(CstFieldExtDTO dto);
}

/**
 * <p>
 * 客户字段扩展表 服务实现类
 * </p>
 *
 * @author kd
 * @since 2023-10-21
 */
@Service
public class CstFieldExtServiceImpl extends ServiceImpl<CstFieldExtMapper, CstFieldExt> implements ICstFieldExtService {
    @Resource
    CstFieldExtMapper cstFieldExtMapper;

    @Resource
    MsCstFieldExtStruct struct;

    @Override
    public String addCstFieldExt(CstFieldExtDTO dto) {
        if (dto.getExtTable()!= null){
            baseMapper.insert(struct.cfeDtoToCfe(dto));
            return "添加完成";
        }
        return "未选择扩展表名";
    }

    @Override
    public boolean removeByIdExceptSysMsg(Integer id) {
        if (isSystemFieldExist(id)) {
            return false;
        }
        return removeById(id);
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public boolean batchRemoveByIds(List<Integer> ids) {
        for (Integer id : ids) {
            //获取代理对象，确保事务有效
            if (((CstFieldExtServiceImpl)AopContext.currentProxy()).isSystemFieldExist(id)) {
                throw new RuntimeException("存在系统字段，禁止删除");
            }
            removeById(id);
        }
        return true;
    }



    /**
     *  判断是否是系统字段
     * @return
     */
    public boolean isSystemFieldExist(Integer id){
        Integer i = cstFieldExtMapper.selectIsSystemById(id);
        return i==1;
    }
}
