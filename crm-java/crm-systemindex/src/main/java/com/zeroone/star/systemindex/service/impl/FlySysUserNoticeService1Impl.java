package com.zeroone.star.systemindex.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysNoticeDTO;
import com.zeroone.star.project.dto.j1.systemindex.noticeRemindDTO;
import com.zeroone.star.project.query.j1.systemindex.FlySysNoticeQuery;
import com.zeroone.star.systemindex.entity.FlySysUserNotice;
import com.zeroone.star.systemindex.mapper.FlySysUserNoticeMapper;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService1;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface NoticeStruct1{
   FlySysNoticeDTO sdoToSDto(FlySysUserNotice flySysUserNotice);
}
@Service
public class FlySysUserNoticeService1Impl extends ServiceImpl<FlySysUserNoticeMapper, FlySysUserNotice>
        implements FlySysUserNoticeService1 {

    @Resource
    NoticeStruct1 noticeStruct1;
    @Override
    public PageDTO<FlySysNoticeDTO> listAllNo(FlySysNoticeQuery flySysNoticeQuery) {
       Page<FlySysUserNotice> flySysUserNoticePage=new Page<>(flySysNoticeQuery.getPageIndex(), flySysNoticeQuery.getPageSize());
       this.page(flySysUserNoticePage);
        return PageDTO.create(flySysUserNoticePage,src -> noticeStruct1.sdoToSDto(src));
    }

    @Override
    public FlySysNoticeDTO getByIdNo(int id) {
        FlySysUserNotice flySysUserNotice=this.getById(id);
        if(flySysUserNotice!=null){
            return noticeStruct1.sdoToSDto(flySysUserNotice);
        }
        return null;
    }
}
