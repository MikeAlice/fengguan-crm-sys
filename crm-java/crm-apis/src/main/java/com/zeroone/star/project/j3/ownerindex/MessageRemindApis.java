package com.zeroone.star.project.j3.ownerindex;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.AddMessageDTO;
import com.zeroone.star.project.dto.j3.ownerindex.MessageDTO;
import com.zeroone.star.project.query.j3.ownerindex.SearchMessageQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 消息通知
 */
public interface MessageRemindApis {

    /**
     * @description: 标记消息为已读（批量操作）
     * @author: Laputa
     * @date: 2023/10/21 19:12
     * @param:
     * @return:
     * 已完成
     **/
    JsonVO<Boolean> markReadMessage(ArrayDTO dto) throws Exception;

    /**
     * @description: 发布消息
     * @author: Laputa
     * @date:
     * @param:
     * @return:
     * 已完成
     **/
    JsonVO<Boolean> addMessage(AddMessageDTO dto) throws Exception;
    /**
     * @description:检索消息接口
     * @author: ZhangJF
     * @date: 2023/10/20 15:51
     * @param:
     * @return:
     *已完成
     **/
    JsonVO<PageDTO<MessageDTO>> queryMessageList(SearchMessageQuery dto);

    /**
     * @description:查看消息详情（通过消息id）
     * @author: ZhangJF
     * @date: 2023/10/20 15:51
     * @param:
     * @return:
     * 已完成
     **/
    JsonVO<MessageDTO> selectMessageById(Integer id);


    /**
     * @description: 消息删除（批量删除）
     * @author: ZhangJF
     * @date: 2023/10/20 20:55
     * @param:
     * @return:
     * 已完成
     **/
    JsonVO<Boolean> deleteMessage(ArrayDTO dto);
}
