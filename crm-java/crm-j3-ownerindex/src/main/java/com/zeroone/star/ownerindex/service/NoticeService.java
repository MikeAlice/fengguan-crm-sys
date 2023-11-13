package com.zeroone.star.ownerindex.service;

import com.zeroone.star.ownerindex.entity.Notice;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.AddNoticeDTO;
import com.zeroone.star.project.dto.j3.ownerindex.QueryNoticeDTO;
import com.zeroone.star.project.query.j3.ownerindex.SearchNoticeQuery;
import com.zeroone.star.project.vo.j3.ownerindex.GetNoticeVO;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

public interface NoticeService {
    /**
     *@Description: 传入需要查找数据
     *@Param: [queryNoticeDTO]
     *@return:java.util.List<com.zeroone.star.ownerindex.entity.Notice>
     *@Author: Mr.Lin
     *@Date: 2023/10/24 22:14
     */
    PageDTO<QueryNoticeDTO> listNotice(SearchNoticeQuery SearchNoticeQuery) throws Exception;

    /**
     *@Description: 增加公告
     *@Param: [addNoticeDTO]
     *@return:int
     *@Author: Mr.Lin
     *@Date: 2023/10/26 22:13
     */
    int addNotice(AddNoticeDTO addNoticeDTO) throws Exception;

    Boolean updateNotice(ArrayDTO dto);

    /*根据id获取公告详细信息*/
    GetNoticeVO getNoticeById(Integer id);

    /*删除公告*/
    void deleteById(ArrayDTO dto);
}
