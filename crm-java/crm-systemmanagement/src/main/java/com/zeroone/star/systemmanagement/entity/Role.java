package com.zeroone.star.systemmanagement.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

@Getter
@Setter
public class Role implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 职责编号
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 分类id
     */
    private Integer sort;

    /**
     * 是否可见
     */
    private Integer visible;

    /**
     * 父id
     */
    private Integer parentID;

    /**
     * 名称
     */
    private String name;

    /**
     * 详细信息
     */
    private String intro;

}
