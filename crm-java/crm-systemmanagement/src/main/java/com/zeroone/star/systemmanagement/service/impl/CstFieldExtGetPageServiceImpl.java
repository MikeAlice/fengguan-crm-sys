package com.zeroone.star.systemmanagement.service.impl;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtGetPageDTO;
import com.zeroone.star.project.query.j1.systemmanagement.CstFieldExtGetPageQuery;
import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.zeroone.star.systemmanagement.mapper.CstFieldExtMapper;
import com.zeroone.star.systemmanagement.service.CstFieldExtGetPageService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service("cstFieldExtGetPageService")
public class CstFieldExtGetPageServiceImpl extends ServiceImpl<CstFieldExtMapper, CstFieldExt> implements CstFieldExtGetPageService {
    @Resource
    CstFieldExtGetPageService service;


    @Override
    public PageDTO<CstFieldExtGetPageDTO> listAll(CstFieldExtGetPageQuery query) {
        return null;
    }
}