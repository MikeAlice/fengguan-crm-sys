package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtGetPageDTO;
import com.zeroone.star.project.query.j1.systemmanagement.CstFieldExtGetPageQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface CstFieldExtGetPageApis {
    /**
     * 获取指定表单扩展字段列表（分⻚+条件）
     * @param query
     * @return 返回查询结果
     */
    JsonVO<PageDTO<CstFieldExtGetPageDTO>> listAll(CstFieldExtGetPageQuery query);
}
