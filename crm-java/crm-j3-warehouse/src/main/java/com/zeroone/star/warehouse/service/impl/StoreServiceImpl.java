package com.zeroone.star.warehouse.service.impl;

import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.warehouse.AddStoreDTO;
import com.zeroone.star.project.dto.j3.warehouse.ImportStoreDTO;
import com.zeroone.star.project.dto.j3.warehouse.ModifyStoreDTO;
import com.zeroone.star.project.dto.j3.warehouse.StoreDTO;
import com.zeroone.star.project.query.j3.warehouse.StoreQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.warehouse.StoreListVO;
import com.zeroone.star.warehouse.entity.Store;
import com.zeroone.star.warehouse.mapper.StoreMapper;
import com.zeroone.star.warehouse.service.StoreService;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;


/**
 * @Description: StoreService实现类
 * @Author: INT
 * @Date: 2023/10/25 13:56
 */
@Service
public class StoreServiceImpl extends ServiceImpl<StoreMapper, Store> implements StoreService {

    @Resource
    private StoreMapper storeMapper;


    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @Resource
    FastDfsClientComponent dfsClient;

    @Resource
    EasyExcelComponent easyExcel;

    @Resource
    UserHolder userHolder;
    @Override
    public String exportStore(ArrayList<Integer> ids) throws Exception {
        ArrayList<Store> stores = new ArrayList<>();
        for (Integer id : ids) {
            Store store = storeMapper.selectById(id);
            stores.add(store);
        }
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        easyExcel.export("仓库表", out, Store.class, stores);
        FastDfsFileInfo uploadInfo = dfsClient.uploadFile(out.toByteArray(), "xlsx");
        out.close();
        if (uploadInfo == null) {
            return null;
        }
        return dfsClient.fetchUrl(uploadInfo, fileServerUrl, true);
    }

    @Override
    public Boolean importStore(ImportStoreDTO dto) throws IOException {
        InputStream inputStream = dto.getExcelFile().getInputStream();
        List<Store> storeList = EasyExcel.read(inputStream).head(Store.class).sheet().doReadSync();
        for(Store store : storeList){
            int insert = storeMapper.insert(store);
            if (insert == 0){
                return false;
            }
        }
        return true;
    }

    @Override
    public JsonVO<Boolean> addStore(AddStoreDTO dto) throws Exception {
        Store store=new Store();
        UserDTO currentUser = userHolder.getCurrentUser();
        store.setCreateUserId(currentUser.getId());
        store.setName(dto.getName());
        store.setSort(dto.getSort());
        store.setVisible(dto.getVisible());
        store.setIntro(dto.getIntro());
        storeMapper.insert(store);

        return JsonVO.success(true);

    }

    @Override
    public PageDTO<StoreDTO> queryPage(StoreQuery dto) {
        Page page = new Page(dto.getPageIndex(),dto.getPageSize());
        LambdaQueryWrapper<Store> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        if (dto.getKeyWord() != null) {
            //仓库名字
            lambdaQueryWrapper.like(Store::getName,dto.getKeyWord());
        }
        page = this.storeMapper.selectPage(page,lambdaQueryWrapper);
        PageDTO<StoreDTO> pageDTO = PageDTO.create(page);
        return pageDTO;
    }
    @Override
    public boolean modifyStore(ModifyStoreDTO dto) {
        Store store = new Store(dto);
        int i = storeMapper.updateById(store);
        return i == 1;
    }

    @Override
    public boolean deleteStore(ArrayList<Integer> ids) {
        if(ids.isEmpty()){
            return false;
        }
        for (Integer id : ids) {
            storeMapper.deleteById(id);
        }
        return true;
    }

    @Override
    public List<StoreListVO> getStoreSelect(String keyWord) {
        if (keyWord == null){
            List<StoreListVO> storeSelect = storeMapper.getStoreSelect();
            return storeSelect;
        }else {
            ArrayList<StoreListVO> storeSelect = new ArrayList<>();
            LambdaQueryWrapper<Store> storeLambdaQueryWrapper = new LambdaQueryWrapper<Store>()
                    .like(Store::getName,keyWord);
            for (Store store : storeMapper.selectList(storeLambdaQueryWrapper)) {
                storeSelect.add(new StoreListVO(store.getStoreId(),store.getName()));
            }
            return storeSelect;
        }
    }
}