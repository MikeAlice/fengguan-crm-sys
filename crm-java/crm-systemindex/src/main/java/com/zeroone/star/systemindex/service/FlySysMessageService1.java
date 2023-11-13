package com.zeroone.star.systemindex.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysMessageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysNoticeDTO;
import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;
import com.zeroone.star.project.query.j1.systemindex.FlySysMessageQuery;
import com.zeroone.star.project.query.j1.systemindex.FlySysNoticeQuery;
import com.zeroone.star.systemindex.entity.FlySysMessage;

import java.util.List;

public interface FlySysMessageService1 extends IService<FlySysMessage> {

    PageDTO<FlySysMessageDTO> listAllMe(FlySysMessageQuery flySysMessageQuery);

    FlySysMessageDTO getByIdMe(int id);




}
