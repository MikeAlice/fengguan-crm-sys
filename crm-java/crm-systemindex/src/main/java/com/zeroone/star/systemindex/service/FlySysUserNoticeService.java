package com.zeroone.star.systemindex.service;

import com.zeroone.star.project.dto.j1.systemindex.noticeRemindDTO;
import com.zeroone.star.systemindex.entity.FlySysUserNotice;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
* @author 86137
* @description 针对表【fly_sys_user_notice(系统员工通知信息)】的数据库操作Service
* @createDate 2023-10-22 14:53:31
*/
public interface FlySysUserNoticeService extends IService<FlySysUserNotice> {

    List<noticeRemindDTO> listByOwnerUserId(Integer userId);
}
