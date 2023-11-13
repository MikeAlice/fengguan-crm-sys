package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtGetDTO;
import com.zeroone.star.project.query.j1.systemmanagement.CstFieldExtGetQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface CstFieldExtGetApis {
    /**
     * 获取当前表单扩展字段列表
     * @param query
     * @return 返回查询结果
     */
    JsonVO<PageDTO<CstFieldExtGetDTO>> listAll(CstFieldExtGetQuery query);
}
