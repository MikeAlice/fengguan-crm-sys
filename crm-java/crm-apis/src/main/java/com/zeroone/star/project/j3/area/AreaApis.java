package com.zeroone.star.project.j3.area;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.area.*;
import com.zeroone.star.project.query.KeyWordQuery;
import com.zeroone.star.project.query.j3.area.ObtainAreaListQuery;
import com.zeroone.star.project.query.j3.area.ObtainAreaTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.area.AreaListVO;

import java.util.List;

/**
 * 地区管理api
 */
public interface AreaApis {

    /**
     * 获取区域名称结构树接口
     * @return 有指定父ID和查询深度条件返回指定数据，否则指定父ID未根节点、深度为1
     * 已完成
     */
    JsonVO<List<AreaTreeInfoDTO>> queryTree(ObtainAreaTreeQuery query);

    /**
     * 获取区域列表接口
     * @param query
     * @return 有分页条件和查询条件返回指定列表，否则返回默认分页和所有数据
     * 已完成
     */
    JsonVO<PageDTO<AreaInfoDTO>> listArea(ObtainAreaListQuery query);

    /**
     * 新增地区接口
     * @param dto
     * @return 新增成功返回true，否则false
     * 已完成
     */
    JsonVO<Boolean> insertArea(InsertAreaDTO dto);

    /**
     * 删除地区接口
     * @param dto
     * @return 删除成功返回true，否则false
     * 删除地区
     * 已完成
     */
    JsonVO<Boolean> deleteArea(DeleteAreaDTO dto);

    /**
     * 修改地区接口
     * @param dto
     * @return  修改成功返回true，否则false
     * 已完成
     */
    JsonVO<Boolean> modifyArea(ModifyAreaDTO dto);

    /***
     *@Description: 获取区域下拉列表
     *@Param: []
     *@Return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j3.area.AreaListVO>
     *@author: Gfeng
     *@DateTime: 2023/10/31 20:09
     */
    JsonVO<List<AreaListVO>> getAreaList(KeyWordQuery keyWordQuery);
}
