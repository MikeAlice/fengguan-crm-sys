package com.zeroone.star.commodity.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.AddNewTypeDTO;
import com.zeroone.star.project.dto.j4.commodity.ModifyTypeDTO;
import com.zeroone.star.project.vo.j4.commodity.DetailedTypeVO;
import com.zeroone.star.project.vo.j4.commodity.SimpleTypeVO;

/**
 * @author Ak5ma1
 */
public interface GoodsTypeService {
    public PageDTO<SimpleTypeVO> findSimpleType( long pageNum, long pageSize);
    public DetailedTypeVO findDetailedType(int attrId);
    public Boolean deleteType(int attrId);

    public Boolean deleteTypeAttr(int attrValueId);

    public Boolean modifyTypeAttr(ModifyTypeDTO modifyTypeDTO);

    public Boolean addType(AddNewTypeDTO addNewTypeDTO);
}
