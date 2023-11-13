package com.zeroone.star.systemindex.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.systemindex.entity.FlySysMessage;
import com.zeroone.star.systemindex.entity.FlySysUserNotice;
import com.zeroone.star.systemindex.mapper.FlySysMessageMapper;
import com.zeroone.star.systemindex.mapper.FlySysUserNoticeMapper;
import com.zeroone.star.systemindex.service.FlySysMessageService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;
@Mapper(componentModel = "spring")
interface MessageStruct {
    messageRemindDTO msgDOToMsgDTO(FlySysMessage flySysMessage);
}
/**
* @author SleepyHead
* @description 针对表【fly_sys_message(消息信息)】的数据库操作Service实现
* @createDate 2023-10-19 21:41:39
*/
@Service
public class FlySysMessageServiceImpl extends ServiceImpl<FlySysMessageMapper, FlySysMessage> implements FlySysMessageService {
    @Resource
    MessageStruct messageStruct;



    @Override
    public List<messageRemindDTO> listByOwnerUserId(Integer ownerUserId) {
        List<FlySysMessage> flySysMessageList = lambdaQuery()
                .eq(FlySysMessage::getOwnerUserId, ownerUserId)
                .list();
        List<messageRemindDTO> dtoList = flySysMessageList.stream()
                .map(message -> messageStruct.msgDOToMsgDTO(message))
                .collect(Collectors.toList());
        return dtoList;
    }
}




