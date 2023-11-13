package com.zeroone.star.warehouse.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.warehouse.AddStoreDTO;
import com.zeroone.star.project.dto.j3.warehouse.StoreDTO;
import com.zeroone.star.project.query.j3.warehouse.StoreQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.warehouse.StoreListVO;
import com.zeroone.star.warehouse.entity.Store;
import com.zeroone.star.project.dto.j3.warehouse.ImportStoreDTO;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.ArrayList;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j3.warehouse.ModifyStoreDTO;
import com.zeroone.star.warehouse.entity.Store;

public interface StoreService extends IService<Store> {

    public String exportStore(ArrayList<Integer> ids) throws Exception;
    public boolean modifyStore(ModifyStoreDTO dto);
    public boolean deleteStore(ArrayList<Integer> ids);
    JsonVO<Boolean> addStore(AddStoreDTO dto) throws Exception;

    PageDTO<StoreDTO> queryPage(StoreQuery dto);

    public Boolean importStore(ImportStoreDTO dto) throws IOException;

    public List<StoreListVO> getStoreSelect(String keyWord);

}