package com.zeroone.star.purchasemanagement.modules.contract.enums;

import cn.hutool.core.map.MapUtil;

import java.util.Map;

/**
 * @author j2
 * @since 2023/10/28
 */
public class PosContractEnum {
    /**
     * 合同状态
     */
    public static Map<Integer, String> statusMap = MapUtil.<Integer, String>builder()
            .put(1, "临时单")
            .put(2, "执行中")
            .put(3, "完成")
            .put(4, "撤销")
            .build();

    /**
     * 支付状态
     */
    public static Map<Integer, String> payStatusMap = MapUtil.<Integer, String>builder()
            .put(1, "未付")
            .put(2, "部分")
            .put(3, "已付")
            .build();

    /**
     * 收票状态
     */
    public static Map<Integer, String> invoiceStatusMap = MapUtil.<Integer, String>builder()
            .put(0, "不需要")
            .put(1, "需要")
            .put(2, "部分")
            .put(3, "全部")
            .build();

    /**
     * 收货状态
     */
    public static Map<Integer, String> receStatusMap = MapUtil.<Integer, String>builder()
            .put(1, "需要")
            .put(2, "已录明细")
            .put(3, "待入库")
            .put(4, "部分")
            .put(5, "全部")
            .build();
}
