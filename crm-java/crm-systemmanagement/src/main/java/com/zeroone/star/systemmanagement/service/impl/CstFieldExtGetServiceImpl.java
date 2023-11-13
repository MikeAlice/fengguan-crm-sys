package com.zeroone.star.systemmanagement.service.impl;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtGetDTO;
import com.zeroone.star.project.query.j1.systemmanagement.CstFieldExtGetQuery;
import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.zeroone.star.systemmanagement.mapper.CstFieldExtMapper;
import com.zeroone.star.systemmanagement.service.CstFieldExtGetService;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;

/**
 * @author SleepyHead
 * @description 针对表【cst_field_ext(客户字段扩展表)】的数据库操作Service实现
 * @createDate 2023-10-20 23:01:26
 */
@Service("cstFieldExtGetService")
public class CstFieldExtGetServiceImpl extends ServiceImpl<CstFieldExtMapper, CstFieldExt> implements CstFieldExtGetService {
    @Resource
    CstFieldExtGetService service;
    @Override
    public PageDTO<CstFieldExtGetDTO> listAll(CstFieldExtGetQuery query) {
        return service.listAll(query);
    }
}
