package com.zeroone.star.ownerindex.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

/**
 * @Description: 消息实体类
 * @Author: your name
 * @Date: 2023/10/24 17:20
 */
@Data
@TableName("fly_sys_message")
public class Message {

    @TableId(type = IdType.AUTO)
    private Integer id;

    private String msgType;

    private String msgTitle;

    private Integer flag;

    private String urlType;

    private Integer urlId;

    private Integer ownerUserId;

    private Date createTime;

    private Date remindTime;
}
