package com.zeroone.star.project.j1.systemindex;

import com.zeroone.star.project.dto.j1.systemindex.messageRemindDTO;
import com.zeroone.star.project.dto.j1.systemindex.noticeRemindDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 系统通知消息提醒接口
 */
public interface SystemMessageRemindApis {
    /**
     * 批量查询消息通知
     * @return 消息通知列表
     */
    JsonVO<List<messageRemindDTO>> queryMessageNotices() throws Exception;

    /**
     * 批量查询公告通知
     * @return 公告通知列表
     */
    JsonVO<List<noticeRemindDTO>> queryAnnouncementNotices() throws Exception;

    /**
     * 将弹窗消息提醒标记为已读
     * @param messageType 0表示消息通知，1表示公告通知
     * @param id 消息id
     * @return 标记结果 成功/失败
     */
    JsonVO<String> markAsRead(int messageType,int id);
}
