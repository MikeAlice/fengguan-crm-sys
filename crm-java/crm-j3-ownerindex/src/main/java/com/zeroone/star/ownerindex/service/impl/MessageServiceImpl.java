package com.zeroone.star.ownerindex.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.ownerindex.entity.Message;
import com.zeroone.star.project.dto.j3.ownerindex.AddMessageDTO;
import com.zeroone.star.project.dto.j3.ownerindex.MessageDTO;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.ownerindex.mapper.MessageMapper;
import com.zeroone.star.ownerindex.service.MessageService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.MessageDTO;
import com.zeroone.star.project.query.j3.ownerindex.SearchMessageQuery;
import org.apache.ibatis.annotations.Delete;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
/**
 * @Description: MessageService实现类
 * @Author: your name
 * @Date: 2023/10/24 17:28
 */
@Service
public class MessageServiceImpl extends ServiceImpl<MessageMapper, Message> implements MessageService {

    @Autowired
    private MessageMapper messageMapper;

    /**
     * 分页条件查询消息，业务逻辑实现
     * @author ZhangJF
     * @date 2023/10/24 18:46
     * @param dto
     * @return com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.ownerindex.MessageDTO>
     */
    @Override
    public PageDTO<MessageDTO> queryPage(SearchMessageQuery dto) {
        Page page = new Page(dto.getPageIndex(),dto.getPageSize());
        LambdaQueryWrapper<Message> lambdaQueryWrapper = new LambdaQueryWrapper<>();

        if (dto.getMsgType() != null) {
            //传入的消息类型不为空
            lambdaQueryWrapper.eq(Message::getMsgType, dto.getMsgType());
        }
        if (dto.getFlag() != null) {
            //传入条件不为空
            lambdaQueryWrapper.eq(Message::getFlag,dto.getFlag());
        }
        if (dto.getKeyWord() != null) {
            lambdaQueryWrapper.like(Message::getMsgTitle,dto.getKeyWord());
        }
        //实现分页
        page = this.messageMapper.selectPage(page,lambdaQueryWrapper);
        PageDTO<MessageDTO> pageDTO = PageDTO.create(page);

        return pageDTO;
    }

    @Override
    public MessageDTO selectMessageById(Integer id) {
        MessageDTO message = messageMapper.selectNewById(id);
        return message;
    }

    @Override
    public void deleteMessage(ArrayDTO dto) {
        for (Integer id : dto.getIds()) {
            messageMapper.deleteById(id);
        }
    }


    @Override
    public Boolean markReadMessage(ArrayDTO dto) throws Exception {
        ArrayList<Integer> ids = dto.getIds();
        UpdateWrapper<Message> updateWrapper = new UpdateWrapper<>();
        updateWrapper.in("id", ids);  // 根据ID列表作为更新条件
        updateWrapper.set("flag", 1);  // 设置要更新的字段和值
        return update(updateWrapper);
    }

    @Override
    public Boolean saveMessage(AddMessageDTO dto) throws Exception {
        Message message = new Message();
        message.setMsgType(dto.getMsgType());
        message.setMsgTitle(dto.getMsgTitle());
        message.setFlag(-1);
        message.setUrlType(dto.getUrlType());
        message.setUrlId(dto.getUrlId());
        message.setOwnerUserId(dto.getOwnerUserId());
        message.setCreateTime(new Date()); // 设置创建时间
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        Date parsedRemindTime = dateFormat.parse(dto.getRemindTime());
        message.setRemindTime(parsedRemindTime); //  将时间字符串根据时间格式转换为Date对象
        return save(message); // 调用MyBatis Plus的save方法插入数据
    }
}
