package com.zeroone.star.systemindex.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysMessageDTO;
import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;
import com.zeroone.star.project.query.j1.systemindex.FlySysMessageQuery;
import com.zeroone.star.systemindex.entity.FlySysMessage;
import com.zeroone.star.systemindex.mapper.FlySysMessageMapper;
import com.zeroone.star.systemindex.service.FlySysMessageService;
import com.zeroone.star.systemindex.service.FlySysMessageService1;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;


@Mapper(componentModel = "spring")
interface MessageStruct1 {
  FlySysMessageDTO sdoToSDto(FlySysMessage flySysMessage);
}
@Service
public class FlySysMessageService1Impl extends ServiceImpl<FlySysMessageMapper, FlySysMessage> implements FlySysMessageService1 {

    @Resource
    MessageStruct1 messageStruct1;
    @Override
    public PageDTO<FlySysMessageDTO> listAllMe(FlySysMessageQuery flySysMessageQuery) {
        Page<FlySysMessage> messagePage=new Page<>(flySysMessageQuery.getPageIndex(), flySysMessageQuery.getPageSize());
        LambdaQueryWrapper<FlySysMessage> lambdaQueryWrapper=new LambdaQueryWrapper<>();
        lambdaQueryWrapper.eq(FlySysMessage::getMsgType,flySysMessageQuery.getMsgType());
          this.page(messagePage,lambdaQueryWrapper);
          return PageDTO.create(messagePage,src -> messageStruct1.sdoToSDto(src));
    }

    @Override
    public FlySysMessageDTO getByIdMe(int id) {
        FlySysMessage message=this.getById(id);
        if(message!=null){
            return messageStruct1.sdoToSDto(message);
        }
        return null;
    }
}
