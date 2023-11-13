package com.zeroone.star.warehouse.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.project.dto.j3.warehouse.ModifyStoreDTO;
import io.github.classgraph.json.Id;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * @Description: 仓库
 * @Author: your name
 * @Date: 2023/10/24 16:49
 */
@Data
@TableName("stock_store")
@NoArgsConstructor
@AllArgsConstructor
public class Store {

//    @ExcelProperty(value = "主键ID", index = 0)
    @TableId(type = IdType.AUTO)
    private Integer storeId;

    @ExcelProperty(value = "姓名", index = 0)
    private String name;

    @ExcelProperty(value = "创建人Id", index = 1)
    private Integer createUserId;

    @ExcelProperty(value = "排序", index = 2)
    private Integer sort;

    @ExcelProperty(value = "是否启用", index = 3)
    private Integer visible;

    @ExcelProperty(value = "简介", index = 4)
    private String intro;

    @ExcelProperty(value = "创建时间", index = 5)
    private Date createTime;

    public Store(ModifyStoreDTO dto) {
        this.storeId = dto.getStoreId();
        this.name = dto.getName();
        this.sort = dto.getSort();
        this.visible = dto.getVisible();
        this.intro = dto.getIntro();
    }
}
