package com.zeroone.star.ownerindex.entity;

import cn.hutool.core.date.DateTime;
import cn.hutool.core.date.DateUtil;
import com.baomidou.mybatisplus.annotation.*;
import com.zeroone.star.project.dto.j3.ownerindex.AddNoticeDTO;
import com.zeroone.star.project.dto.j3.ownerindex.QueryNoticeDTO;
import io.github.classgraph.json.Id;
import io.swagger.models.auth.In;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * @Description: 公告实体类
 * @Author: your name
 * @Date: 2023/10/24 17:16
 */
@Data
@TableName("fly_sys_user_notice")
@NoArgsConstructor
@AllArgsConstructor
public class Notice {
    @TableId(value = "id",type = IdType.AUTO)
    private Integer id;

    private String title;

    private String content;

    private Integer status = 0;

    private Integer ownerUserId;

    private Integer createUserId;

    private Date createTime;


    public QueryNoticeDTO transition(Notice notice){
        QueryNoticeDTO queryNoticeDTO = new QueryNoticeDTO();
        queryNoticeDTO.setId(notice.getId());
        queryNoticeDTO.setStatus(notice.getStatus());
        queryNoticeDTO.setTitle(notice.getTitle());
        queryNoticeDTO.setContent(notice.getContent());
        DateTime createTime = DateUtil.date(notice.getCreateTime());
        queryNoticeDTO.setCreateTime(createTime);
        queryNoticeDTO.setCreateUserId(notice.getCreateUserId());
        queryNoticeDTO.setOwnerUserId(notice.getOwnerUserId());
        return queryNoticeDTO;
    }

    public Notice reTransition(AddNoticeDTO addNoticeDTO){
        Notice notice = new Notice();
        notice.setId(null);
        notice.setTitle(addNoticeDTO.getTitle());
        notice.setContent(addNoticeDTO.getContent());
//        DateTime createTime = DateUtil.date(addNoticeDTO.getCreateTime());
        notice.setCreateTime(createTime);
//        notice.setCreateUserId(addNoticeDTO.getCreateUserId());
        notice.setOwnerUserId(addNoticeDTO.getOwnerUserId());
        return notice;
    }

    public Notice(Integer id, Integer status) {
        this.id = id;
        this.status = status;
    }
}
