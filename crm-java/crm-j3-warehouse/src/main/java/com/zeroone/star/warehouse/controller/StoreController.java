package com.zeroone.star.warehouse.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.warehouse.*;
import com.zeroone.star.project.j3.warehouse.StoreApi;
import com.zeroone.star.project.query.KeyWordQuery;
import com.zeroone.star.project.query.j3.warehouse.StoreQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.warehouse.StoreListVO;
import com.zeroone.star.warehouse.entity.Store;
import com.zeroone.star.warehouse.service.StoreService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;


import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


/**
 * <p>
 * 描述：
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 巧克力张张包
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j3-controller-warehouse")
@Api(tags = "基础数据-仓库管理")
public class StoreController implements StoreApi {

    @Autowired
    private StoreService storeService;

    @ApiOperation(value = "修改仓库信息")
    @Override
    @PostMapping("/modify-store-info")
    public JsonVO<Boolean> modifyStoreInfo(ModifyStoreDTO dto) {
        boolean result = storeService.modifyStore(dto);
        return JsonVO.success(result);
    }

    @ApiOperation(value = "删除仓库",notes = "将所选仓库的storeId封装成list传来,只删一条也是一样操作，多选删除和删除共用接口")
    @Override
    @PostMapping("/delete-store")
    public JsonVO<Boolean> deleteStore(@RequestBody ArrayDTO dto) {
        ArrayList<Integer> ids = dto.getIds();
        if (ids.isEmpty()){
            throw new RuntimeException("参数不允许为空");
        }
        boolean result = storeService.deleteStore(ids);
        return JsonVO.success(result);
    }

    @ApiOperation(value = "导出仓库",notes = "多选仓库导出，需要将所选仓库的id传来")
    @Override
    @PostMapping("/export-store")
    public JsonVO<String> exportStore(@RequestBody ArrayDTO dto) throws Exception {
        ArrayList<Integer> ids = dto.getIds();
        if (ids.size() == 0){
            throw new RuntimeException("参数不允许为空");
        }
        String url = storeService.exportStore(ids);
        return JsonVO.success(url);
    }

    @Override
    @ApiOperation(value = "导入仓库")
    @PostMapping("/import-store")
    public JsonVO<Boolean> importStore(ImportStoreDTO dto) throws IOException {
        MultipartFile excelFile = dto.getExcelFile();
        if (excelFile.isEmpty()){
            throw new RuntimeException("参数不允许为空");
        }
        Boolean b = storeService.importStore(dto);
        if(b == false){
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }

    @Override
    @ApiOperation(value = "查询仓库（分页或仓库名）")
    @GetMapping("/query-store")
    public JsonVO<PageDTO<StoreDTO>> queryStoreList(@Validated StoreQuery dto) {
        PageDTO<StoreDTO> pageList =storeService.queryPage(dto);
        return  JsonVO.success(pageList);
    }

    @Override
    @ApiOperation(value = "增加仓库")
    @PostMapping("/add-store")
    public JsonVO<Boolean> addStore(AddStoreDTO dto) throws Exception {
        return storeService.addStore(dto);
    }

    @Override
    @ApiOperation(value = "获取仓库下拉列表")
    @GetMapping("/getStoreSelect")
    public JsonVO<List<StoreListVO>> getStoreList(KeyWordQuery keyWordQuery) {
        List<StoreListVO> storeSelect = storeService.getStoreSelect(keyWordQuery.getKeyWord());
        return JsonVO.success(storeSelect);
    }
}
