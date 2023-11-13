package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysConfigDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

public interface CstFieldExtApis {



    /**
     * 添加扩展字段
     * @param dto  字段对象
     * @return 提示信息是否成功
     */
    @ApiOperation(value = "添加扩展字段")
    @PostMapping("add")
    JsonVO<String> addCstFieldExt(CstFieldExtDTO dto);

    /**
     * 根据字段id删除扩展字段
     * @param extId  字段id
     * @return 提示信息是否成功
     */
    JsonVO<String> removeCstFieldExt(Integer extId);

    /**
     * 根据字段id数组删除扩展字段
     * @param extIds 字段id数组
     * @return 提示信息是否成功
     */
    JsonVO<String> removeBatchCstFieldExt(List<Integer> extIds);
}
