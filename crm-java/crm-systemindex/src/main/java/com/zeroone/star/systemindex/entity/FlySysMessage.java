package com.zeroone.star.systemindex.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * @TableName fly_sys_message
 */
@TableName(value ="fly_sys_message")
@Data
public class FlySysMessage implements Serializable {
    private Integer id;

    private String msgType;

    private String msgTitle;

    private Integer flag;

    private String urlType;

    private Integer urlId;

    private Integer ownerUserId;

    private Date createTime;

    private Date remindTime;

    private static final long serialVersionUID = 1L;
}