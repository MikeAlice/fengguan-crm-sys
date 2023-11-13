package com.zeroone.star.ownerindex.service;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.ownerindex.entity.Message;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.AddMessageDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.MessageDTO;
import com.zeroone.star.project.query.j3.ownerindex.SearchMessageQuery;

import java.util.List;
public interface MessageService{
    public Boolean markReadMessage(ArrayDTO dto) throws Exception;

    public Boolean saveMessage(AddMessageDTO dto) throws Exception;
    /**
     * 根据分页条件查询消息列表
     * @author ZhangJF
     * @date 2023/10/24 18:46
     * @param dto
     * @return com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.ownerindex.MessageDTO>
     */
    PageDTO<MessageDTO> queryPage(SearchMessageQuery dto);

    /**
     * 查看消息详情（根据消息id）
     * @author ZhangJF
     * @date 2023/10/24 20:03
     * @param id
     * @return com.zeroone.star.project.dto.j3.ownerindex.MessageDTO
     */
    MessageDTO selectMessageById(Integer id);

    /**
     * 实现批量删除
     * @author ZhangJF
     * @date 2023/10/24 20:37
     * @param dto
     * @return void
     */
    void deleteMessage(ArrayDTO dto);
}
