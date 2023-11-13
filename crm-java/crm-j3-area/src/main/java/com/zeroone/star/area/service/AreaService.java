package com.zeroone.star.area.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.area.entity.Area;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.area.*;
import com.zeroone.star.project.query.j3.area.ObtainAreaListQuery;
import com.zeroone.star.project.query.j3.area.ObtainAreaTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.area.AreaListVO;

import java.util.List;

public interface AreaService extends IService<Area> {

    // 获取区域名称结构树 接口
    List<AreaTreeInfoDTO> queryTree(ObtainAreaTreeQuery query);

    // 获取区域列表 接口
    PageDTO<AreaInfoDTO> listArea(ObtainAreaListQuery query);

    public JsonVO<Boolean> insertArea(InsertAreaDTO dto);

    public JsonVO<Boolean> deleteArea(DeleteAreaDTO dto);

    public JsonVO<Boolean> modifyArea(ModifyAreaDTO dto);

    public List<AreaListVO> getAreaList(String keyWord);
}
