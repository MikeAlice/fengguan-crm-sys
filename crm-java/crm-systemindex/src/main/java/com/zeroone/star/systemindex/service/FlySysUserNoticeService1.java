package com.zeroone.star.systemindex.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysNoticeDTO;
import com.zeroone.star.project.dto.j1.systemindex.noticeRemindDTO;
import com.zeroone.star.project.query.j1.systemindex.FlySysNoticeQuery;
import com.zeroone.star.systemindex.entity.FlySysUserNotice;

import java.util.List;

/**
* @author 86137
* @description 针对表【fly_sys_user_notice(系统员工通知信息)】的数据库操作Service
* @createDate 2023-10-22 14:53:31
*/
public interface FlySysUserNoticeService1 extends IService<FlySysUserNotice> {
    PageDTO<FlySysNoticeDTO> listAllNo(FlySysNoticeQuery flySysNoticeQuery);

    FlySysNoticeDTO getByIdNo(int id);
}
