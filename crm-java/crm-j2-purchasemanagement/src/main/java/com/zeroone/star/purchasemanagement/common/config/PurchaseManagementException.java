package com.zeroone.star.purchasemanagement.common.config;

import lombok.Data;

/**
 * 采购管理模块自定义异常
 *
 * @author j2
 * @since 2023/10/20
 */
@Data
public class PurchaseManagementException extends RuntimeException {
    public final static Integer CODE = 10120;

    private String message;

    public PurchaseManagementException(String message) {
        super(message);
        this.message = message;
    }
}
