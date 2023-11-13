package com.zeroone.star.commodity.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoods;
import com.zeroone.star.commodity.entity.FlyGoodsSpec;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.SpecDTO;
import com.zeroone.star.project.query.j4.commodity.CommoditySpecQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 商品属性（规格）表 服务类
 * </p>
 *
 * @author Tezz
 * @since 2023-10-25
 */
public interface IFlyGoodsSpecService extends IService<FlyGoodsSpec> {

    /**
     * <p>
     * 描述：商品规格声明式服务
     * </p>
     *
     * @author Tezz
     * @version 1.0.0
     */

//@FeignClient(
//        name = "${cpp.Spec.name}",
//        url = "${cpp.Spec.url}"
//        fallbackFactory = CppServiceFallBack.class,
//        configuration = FeignConfiguration.class
//)


        /**
         * 商品规格分页查询
         * @param query 获取
         * @return 获取商品规格列表(分页+条件)
         */
        PageDTO<SpecDTO> queryAll(CommoditySpecQuery query);


        /**
         * 修改商品规格
         * @param specDTO
         * @return 修改后的数据
         */
        boolean modifyData(SpecDTO specDTO);

        /**
         * 删除商品规格
         * @param specId
         * @return 删除数据
         */
        boolean deleteData(int specId);
        /**
         * 添加商品规格
         * @param specDTO
         * @return 新增数据
         */
        boolean addData(SpecDTO specDTO);



}
