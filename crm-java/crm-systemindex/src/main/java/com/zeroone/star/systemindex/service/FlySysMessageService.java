package com.zeroone.star.systemindex.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysMessageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysNoticeDTO;
import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;

import com.zeroone.star.project.query.j1.systemindex.FlySysMessageQuery;
import com.zeroone.star.project.query.j1.systemindex.FlySysNoticeQuery;
import com.zeroone.star.systemindex.entity.FlySysMessage;

import java.util.List;

public interface FlySysMessageService extends IService<FlySysMessage> {



    List<messageRemindDTO> listByOwnerUserId(Integer id);
}
