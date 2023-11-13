package com.zeroone.star.project.j3.ownerindex;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.*;
import com.zeroone.star.project.query.j3.ownerindex.SearchNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.ownerindex.GetNoticeVO;

/**
 * 公告通知
 */
public interface  NoticeRemindApis {

    /***
     *@Description: 查看指定公告接口
     *@Param: 查看指定公告相关数据
     *@Return: 查看成功，成功为true
     * 未完成
     */
    JsonVO<GetNoticeVO> getNotice(Integer id);


    /***
     *@Description: 删除公告通知接口
     *@Param: 删除公告通知相关数据
     *@Return: 删除成功，成功为true
     * 未完成
     */
    JsonVO<Boolean> removeNotice(ArrayDTO dto);



    /***
     *@Description: 标记已读公告通知接口
     *@Param: 标记已读公告通知相关数据
     *@Return: 标记成功，成功为true
     * 已完成
     */
    JsonVO<Boolean> updateNotice(ArrayDTO dto);




    /**
     *@Description: 发布公告
     *@Param: [com.zeroone.star.project.dto.j3.ownerindex.AddNoticeDTO]
     *@Return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     *@author: Gfeng
     *@DateTime: 2023/10/22 12:13
     * 半完成（待改进）
     */
    JsonVO<Boolean> addNotice(AddNoticeDTO dto) throws Exception;

   /**
    *@Description: 获取系统通告
    *@Param: []
    *@return:com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.ownerindex.QueryNotionDTO>>
    *@Author: Mr.Lin
    *@Date: 2023/10/22 17:38
    * 已完成
    */
   JsonVO<PageDTO<QueryNoticeDTO>> QueryNoticePage(SearchNoticeQuery searchNoticeQuery) throws Exception;
    
    



}
