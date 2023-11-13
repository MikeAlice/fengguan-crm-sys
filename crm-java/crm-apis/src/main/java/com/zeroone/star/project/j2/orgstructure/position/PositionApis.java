package com.zeroone.star.project.j2.orgstructure.position;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.AddPositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.DeletePositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.QueryPositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.UpdatePositionDTO;
import com.zeroone.star.project.query.j2.orgstructure.position.GetPositionNameTreeQuery;
import com.zeroone.star.project.query.j2.orgstructure.position.PositionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.position.GetNamePositionV0;
import com.zeroone.star.project.vo.j2.orgstructure.position.PositionTreeVO;

import java.util.List;

import java.util.List;

/**
 * 岗位接口API定义
 *
 * @author j2
 * @version 1.0.0
 */
public interface PositionApis {
    /**
     * 岗位分页查询
     * @param positionQuery 查询条件
     * @return  查询结果
     */
    JsonVO<PageDTO<QueryPositionDTO>> queryAll(PositionQuery positionQuery);

    /**
     * 下拉列表部门名称
     * @return  查询结果
     */
    JsonVO<List<GetNamePositionV0>> listNameAll(String positionName);

    JsonVO<List<PositionTreeVO>>listNameTree(GetPositionNameTreeQuery getPositionNameTreeQuery);

    /**
     * 新增岗位
     * @param addPositionDTO 新增岗位DTO
     * @return 统一响应模型
     */
    JsonVO<Void> addPosition(AddPositionDTO addPositionDTO);

    /**
     * 修改岗位
     * @param updatePositionDTO 修改岗位DTO
     * @return 统一响应模型
     */
    JsonVO<Void> updatePosition(UpdatePositionDTO updatePositionDTO);

    /**
     * 删除岗位
     * @param positionId 删除岗位DTO
     * @return 统一响应模型
     */
    JsonVO<Void> deletePosition(Integer positionId);

}
