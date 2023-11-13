package com.zeroone.star.orgstructure.modules.dept.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Builder;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 部门表
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Getter
@Setter
@Builder
@TableName("fly_sys_dept")
public class DeptEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String name;

    @TableField("parentID")
    private Integer parentID;

    private Integer sort;

    private Integer visible;

    private String tel;

    private String fax;

    private String intro;


}
