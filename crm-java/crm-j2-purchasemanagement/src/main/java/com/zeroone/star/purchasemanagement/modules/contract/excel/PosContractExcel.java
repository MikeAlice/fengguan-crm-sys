package com.zeroone.star.purchasemanagement.modules.contract.excel;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

/**
 * @author 叔
 * @date 2023/10/31 20:54
 */
@Data
public class PosContractExcel implements Serializable {
    private static final long serialVersionUID = 1L;

    @ExcelProperty(value = "标题", index = 0)
    private String title;

    @ExcelProperty(value = "编号", index = 1)
    private String ContractNo;

    @ExcelProperty(value = "供应商", index = 2)
    private String supplierName;

    @ExcelProperty(value = "合同金额", index = 3)
    private BigDecimal money;

    @ExcelProperty(value = "采购金额",index = 4)
    private BigDecimal goodsMoney;

    @ExcelProperty(value = "去零金额",index = 5)
    private BigDecimal zeroMoney;

    @ExcelProperty(value = "支付金额",index = 6)
    private BigDecimal payMoney;

    @ExcelProperty(value = "尚欠金额",index = 7)
    private BigDecimal oweMoney;

    @ExcelProperty(value = "采购日期",index = 8,converter = ExcelDateConverter.class)
    private Date startDate;

    @ExcelProperty(value = "预计到货日期",index = 9,converter =ExcelDateConverter.class )
    private Date endDate;

    @ExcelProperty(value = "创建时间",index = 10,converter = ExcelDateTimeConverter.class)
    private Date createTime;
}
