package com.zeroone.star.orgstructure.modules.dept.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.modules.dept.entity.DeptEntity;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.AddDeptDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.DeptDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.QueryDeptDTO;
import com.zeroone.star.project.query.j2.orgstructure.dept.DeptQuery;
import com.zeroone.star.project.query.j2.orgstructure.dept.GetDeptNameTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.dept.DeptTreeVO;
import com.zeroone.star.project.vo.j2.orgstructure.dept.GetNameDeptV0;

import java.util.List;

/**
 * <p>
 * 部门表 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
public interface DeptService extends IService<DeptEntity> {

    /**
     * 分页查询所有数据
     *
     * @param deptQuery 查询条件
     * @return 返回值
     */
    PageDTO<QueryDeptDTO> listAll(DeptQuery deptQuery);
    /**
     * 新增部门数据
     * @param dto 数据对象
     * @return 新增结果
     */
    JsonVO<Long> addDept(AddDeptDTO dto);

    /**
     * 修改部门数据
     * @param dto 修改对象
     * @return 修改结果
     */
    JsonVO<Long> updateDept(DeptDTO dto);

    /**
     * 删除部门数据
     * @param id 数据对象id
     * @return 删除结果
     */
    JsonVO<Long> deleteDept(Integer id);

    JsonVO<List<DeptTreeVO>> getNameTree(GetDeptNameTreeQuery getDeptNameTreeQuery);

    /**
     * 获取下拉列表部门名称数据
     *
     * @return 获取结果
     */
    JsonVO<List<GetNameDeptV0>> getnamedept(String deptName);
}
