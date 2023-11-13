package com.zeroone.star.ownerindex.mapper;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.ownerindex.entity.Message;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ownerindex.MessageDTO;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Mapper;


@Mapper
public interface MessageMapper extends BaseMapper<Message> {

    /**
     * 查看消息详情
     * @author ZhangJF
     * @date 2023/10/24 20:30
     * @param id
     * @return com.zeroone.star.project.dto.j3.ownerindex.MessageDTO
     */
    @Select("select * from fly_sys_message where id = ${id}")
    MessageDTO selectNewById(Integer id);

}
