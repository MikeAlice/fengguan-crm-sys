package com.zeroone.star.orgstructure.modules.user.excel;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 用户Excel表格实体类
 *
 * @author 汐
 * @since 2023/10/27
 */
@Data
public class UserExcel implements Serializable {
    private static final long serialVersionUID = 1L;

    @ExcelProperty(value = "账号", index = 0)
    private String account;
    @ExcelProperty(value = "姓名", index = 1)
    private String name;
    @ExcelProperty(value = "性别", index = 2)
    private String gender;
    @ExcelProperty(value = "手机", index = 3)
    private String mobile;
    @ExcelProperty(value = "QQ", index = 4)
    private String qicq;
    @ExcelProperty(value = "邮箱", index = 5)
    private String email;
    @ExcelProperty(value = "部门", index = 7)
    private String dept;
    @ExcelProperty(value = "职务", index = 8)
    private String position;
    @ExcelProperty(value = "角色", index = 6)
    private String role;
}
