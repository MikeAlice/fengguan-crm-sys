package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysAddMethodDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMethodDTO;
import com.zeroone.star.project.query.j1.systemmanagement.GetMethodListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MethodListVO;

public interface FlySysMethodApis {
    /**
     *新增权限
     * @param flySysMethodDTO
     * @return
     */
    JsonVO<String> addMethod(FlySysAddMethodDTO flySysMethodDTO);

    /**
     * 修改权限
     * @param flySysMethodDTO
     * @return
     */
    JsonVO<String> modifyMethod(FlySysMethodDTO flySysMethodDTO);

    /**
     * 获取权限列表
     * @param getMethodListQuery 获取权限列表查询参数
     * @return 权限列表分页vo模型
     */
    JsonVO<PageDTO<MethodListVO>> getMethodList(GetMethodListQuery getMethodListQuery);

    /**
     * 删除权限
     * @param flySysMethodDTO
     * @return
     */
    JsonVO<Boolean> DeleteMethod(FlySysMethodDTO flySysMethodDTO);
}
