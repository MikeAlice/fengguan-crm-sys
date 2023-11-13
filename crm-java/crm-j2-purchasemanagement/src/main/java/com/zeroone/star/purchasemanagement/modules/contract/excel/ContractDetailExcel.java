package com.zeroone.star.purchasemanagement.modules.contract.excel;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * 采购明细Excel实体类
 *
 * @author 汐
 * @since 2023/10/31
*/
@Data
public class ContractDetailExcel implements Serializable {
    private static final long serialVersionUID = 1L;

    @ExcelProperty(value = "采购单号", index = 0)
    private String contractName;
    @ExcelProperty(value = "商品编号", index = 1)
    private Integer goodsId;
    @ExcelProperty(value = "SKUID", index = 2)
    private Integer skuId;
    @ExcelProperty(value = "商品名称", index = 3)
    private String goodsName;
    @ExcelProperty(value = "SKU名称", index = 4)
    private String skuName;
    @ExcelProperty(value = "数量", index = 5)
    private String num;
    @ExcelProperty(value = "采购单价", index = 6)
    private BigDecimal salePrice;
    @ExcelProperty(value = "金额", index = 7)
    private BigDecimal goodsMoney;
    @ExcelProperty(value = "入库数量", index = 8)
    private String intoNum;
}
