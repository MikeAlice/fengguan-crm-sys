package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtplusDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.CstFieldExtplusUpdateVO;
import com.zeroone.star.project.vo.j1.systemmanagement.CstFieldExtplusVO;

import java.util.List;

public interface CstFieldExtplusApis {

    /**
     * 获取字段数据类型
     * @param cstFieldExtplusDTO 从前端获取的字段对应的id
     * @return 返回的是字段的数据类型
     */
    JsonVO<CstFieldExtplusVO> getFieldType(CstFieldExtplusDTO cstFieldExtplusDTO);

    /**
     * 修改扩展字段
     * @param cstFieldExtplusDTOList 从前端获取要修改的字段对应的id
     * @return 返回修改后的字段所有休息
     */
    public JsonVO<List<CstFieldExtplusUpdateVO>> updateField(List<CstFieldExtplusDTO> cstFieldExtplusDTOList);

}
