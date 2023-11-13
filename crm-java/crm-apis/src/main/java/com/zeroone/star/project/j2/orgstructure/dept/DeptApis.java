package com.zeroone.star.project.j2.orgstructure.dept;

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
 * 部门接口API定义
 *
 * @author j2
 * @version 1.0.0
 */
public interface DeptApis {
    /**
     * 部门分页查询
     *
     * @param deptQuery 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<QueryDeptDTO>> queryAll(DeptQuery deptQuery);

    /**
     * 获取部门名称列表数据
     *
     * @return 查询结果
     */
    JsonVO<List<GetNameDeptV0>> listNameAll(String deptName);

    /**
     * 添加部门到数据库
     *
     * @param dto 要添加的部门对象
     * @return 新增数据唯一编号
     */
    JsonVO<Long> addDept(AddDeptDTO dto);

    /**
     * 修改部门内容
     *
     * @param dto 要修改的部门对象
     * @return 修改后的部门
     */
    JsonVO<Long> modifyDept(DeptDTO dto);

    /**
     * 添加部门到数据库
     *
     * @param id 要删除的部门对象
     * @return 删除部门的编号
     */
    JsonVO<Long> removeDept(Integer id);


    JsonVO<List<DeptTreeVO>> listNameTree(GetDeptNameTreeQuery getDeptNameTreeQuery);


}
