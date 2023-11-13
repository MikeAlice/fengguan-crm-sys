package com.zeroone.star.project.j1.systemindex;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysMessageDTO;
import com.zeroone.star.project.dto.j1.systemindex.FlySysNoticeDTO;
import com.zeroone.star.project.query.j1.systemindex.FlySysMessageQuery;
import com.zeroone.star.project.query.j1.systemindex.FlySysNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface SystemMessageApis {
    /**
     * 分页获取提示信息
     * @param flySysMessageQuery
     * @return 返回查询结果
     */
      JsonVO<PageDTO<FlySysMessageDTO>> queryMessageAll(FlySysMessageQuery flySysMessageQuery);

    /**
     * 通过id获取提示信息
     * @param id
     * @return 返回查询结果
     */
      JsonVO<FlySysMessageDTO> queryMessageById(int id);

    /**
     * 分页获取系统公告
     * @param flySysNoticeQuery
     * @return 返回查询结果
     */
    JsonVO<PageDTO<FlySysNoticeDTO>> queryNoticeAll(FlySysNoticeQuery flySysNoticeQuery);

    /**
     * 通过id获取系统公告
     * @param id
     * @return 返回查询结果
     */
    JsonVO<FlySysNoticeDTO> queryNoticeById(int id);

}
