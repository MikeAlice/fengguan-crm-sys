package com.zeroone.star.systemindex.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;
import com.zeroone.star.project.dto.j1.systemindex.noticeRemindDTO;
import com.zeroone.star.systemindex.entity.FlySysMessage;
import com.zeroone.star.systemindex.entity.FlySysUserNotice;
import com.zeroone.star.systemindex.service.FlySysUserNoticeService;
import com.zeroone.star.systemindex.mapper.FlySysUserNoticeMapper;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;
@Mapper(componentModel = "spring")
interface NoticeStruct {
    noticeRemindDTO noticeDOTonoticeDTO(FlySysUserNotice flySysUserNotice);
}
/**
* @author 86137
* @description 针对表【fly_sys_user_notice(系统员工通知信息)】的数据库操作Service实现
* @createDate 2023-10-22 14:53:31
*/
@Service
public class FlySysUserNoticeServiceImpl extends ServiceImpl<FlySysUserNoticeMapper, FlySysUserNotice>
    implements FlySysUserNoticeService{
    @Resource
    NoticeStruct noticeStruct;
    @Override
    public List<noticeRemindDTO> listByOwnerUserId(Integer ownerUserId) {
        List<FlySysUserNotice> noticeList = lambdaQuery()
                .eq(FlySysUserNotice::getOwnerUserId,ownerUserId)
                .list();
        List<noticeRemindDTO> dtoList = noticeList.stream()
                .map(notice -> noticeStruct.noticeDOTonoticeDTO(notice))
                .collect(Collectors.toList());
        return dtoList;
    }
}




