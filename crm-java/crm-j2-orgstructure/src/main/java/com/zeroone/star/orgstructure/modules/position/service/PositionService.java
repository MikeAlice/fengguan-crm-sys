package com.zeroone.star.orgstructure.modules.position.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.modules.position.entity.PositionEntity;
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

/**
 * <p>
 * 职位表 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
public interface PositionService extends IService<PositionEntity> {
    /**
     * 获取下拉列表岗位名称数据
     *
     * @return 获取结果
     */
    JsonVO<List<GetNamePositionV0>> getnameposition(String positionName);

    PageDTO<QueryPositionDTO> listAll(PositionQuery positionQuery);
    JsonVO<List<PositionTreeVO>> listNameTree(GetPositionNameTreeQuery getPositionNameTreeQuery);

    /**
     * 新增岗位
     * @param addPositionDTO 新增岗位DTO
     */
    void addPosition(AddPositionDTO addPositionDTO);

    /**
     * 修改岗位
     * @param updatePositionDTO 修改岗位DTO
     */
    void updatePosition(UpdatePositionDTO updatePositionDTO);

    /**
     * 删除岗位
     * @param positionId 删除岗位DTO
     */
    void deletePosition(Integer positionId);
}
