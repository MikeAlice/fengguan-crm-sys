package com.zeroone.star.project.j3.warehouse;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.warehouse.*;
import com.zeroone.star.project.query.KeyWordQuery;
import com.zeroone.star.project.query.j3.warehouse.StoreQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.area.AreaListVO;
import com.zeroone.star.project.vo.j3.warehouse.StoreListVO;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public interface StoreApi {
    /**
     *描述：修改仓库信息接口
     * @param dto 修改仓库想换数据
     * @return 修改结果，成功为true
     * 已完成
     **/
    JsonVO<Boolean> modifyStoreInfo(ModifyStoreDTO dto);
    /**
     *描述：删除仓库接口
     * @param  dto 需要删除仓库的id集合
     * @return 删除结果，成功为true
     * 已完成
     * */
    JsonVO<Boolean> deleteStore(ArrayDTO dto);

    /**
     *@Description: 导出仓库
     *@Param: [com.zeroone.star.project.dto.j3.ArrayDTO]
     *@Return: com.zeroone.star.project.vo.JsonVO<java.lang.String>
     *@author: Gfeng
     *@DateTime: 2023/10/24 22:32
     * 已完成
     */
    JsonVO<String> exportStore(ArrayDTO dto) throws Exception;

    /**
     *@Description: 导入仓库
     *@Param: [com.zeroone.star.project.dto.j3.warehouse.ImportStoreDTO]
     *@Return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     *@author: Gfeng
     *@DateTime: 2023/10/22 16:39
     * 已完成
     */
    JsonVO<Boolean> importStore(ImportStoreDTO dto) throws IOException;
    /**
     * @description:获取仓库列表
     * @author: INT
     * @param:
     * @return:
     * 已完成
     **/
    JsonVO<PageDTO<StoreDTO>> queryStoreList(StoreQuery dto);

    /**
     *描述：添加仓库接口
     * @param dto 添加仓库数据
     * @return 修改结果，成功为true
     * 已完成
     * */
    JsonVO<Boolean> addStore(AddStoreDTO dto) throws Exception;

    /**
     *@Description: 获取仓库下拉列表
     *@Param: []
     *@Return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j3.warehouse.StoreListVO>
     *@author: Gfeng
     *@DateTime: 2023/10/31 20:11
     */
    JsonVO<List<StoreListVO>> getStoreList(KeyWordQuery keyWordQuery);
}
