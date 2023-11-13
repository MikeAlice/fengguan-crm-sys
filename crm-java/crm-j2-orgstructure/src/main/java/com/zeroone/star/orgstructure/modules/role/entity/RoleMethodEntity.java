package com.zeroone.star.orgstructure.modules.role.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 角色-系统方法关联表
 * </p>
 *
 * @author j2
 * @since 2023-10-21
 */
@Getter
@Setter
@TableName("fly_sys_role_method")
public class RoleMethodEntity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 角色-系统方法关联ID
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 角色ID
     */
    private Integer roleId;

    /**
     * 系统方法ID
     */
    private Integer methodId;


}
