package com.zeroone.star.orgstructure.common.config;

import lombok.Data;

/**
 * 组织结构模块自定义异常
 *
 * @author j2
 * @since 2023/10/20
 */
@Data
public class OrgStructureException extends RuntimeException {
    public final static Integer CODE = 10110;

    private String message;

    public OrgStructureException(String message) {
        super(message);
        this.message = message;
    }
}
