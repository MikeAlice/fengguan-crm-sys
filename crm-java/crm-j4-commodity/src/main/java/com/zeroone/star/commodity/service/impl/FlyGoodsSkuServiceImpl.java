package com.zeroone.star.commodity.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import cn.hutool.db.PageResult;
import cn.hutool.json.JSONUtil;
import com.alibaba.druid.util.StringUtils;
import com.alibaba.nacos.common.utils.JacksonUtils;
import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoodsSku;
import com.zeroone.star.commodity.mapper.FlyGoodsSkuMapper;
import com.zeroone.star.commodity.service.IFlyGoodsSkuService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.commodity.tools.RedisTool;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.CommoditySkuDto;
import com.zeroone.star.project.dto.j4.commodity.CommodityEditSkuDto;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.query.j4.commodity.GoodsSkuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.ListOperations;
import org.springframework.data.redis.core.RedisConnectionUtils;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.ValueOperations;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;

import java.util.*;

/**
 * <p>
 * 商品sku规格价格信息表 服务实现类
 * </p>
 *
 * @author zhenglw
 * @since 2023-10-24
 */
@Service
public class FlyGoodsSkuServiceImpl extends ServiceImpl<FlyGoodsSkuMapper, FlyGoodsSku> implements IFlyGoodsSkuService {

    @Autowired
    private FlyGoodsSkuMapper flyGoodsSkuMapper;

    @Autowired
    private RedisTemplate<String,Object> redisTemplate;


    @Override
    public JsonVO<Boolean> modifyCommoditySku(CommodityEditSkuDto commodityEditSkuDto) {
        if(commodityEditSkuDto.getGoodsId() != null){
            QueryWrapper<FlyGoodsSku> queryWrapper = new QueryWrapper<>();
            queryWrapper.eq("goods_id",commodityEditSkuDto.getGoodsId());
            FlyGoodsSku flyGoodsSku = new FlyGoodsSku();
            BeanUtil.copyProperties(commodityEditSkuDto,flyGoodsSku);
            int update = flyGoodsSkuMapper.update(flyGoodsSku, queryWrapper);
            if(update == 0){
                throw new RuntimeException("SKU属性修改失败!");
            }

        }else {
            FlyGoodsSku flyGoodsSku = new FlyGoodsSku();
            BeanUtil.copyProperties(commodityEditSkuDto,flyGoodsSku);
            int insert = flyGoodsSkuMapper.insert(flyGoodsSku);
            if(insert == 0){
                return JsonVO.create(null,ResultStatus.FAIL.getCode(),"新增失败");
            }
        }
        Set<String> keys = redisTemplate.keys(RedisTool.GOODS_SKU_LIST_ID + "*");
        //删除缓存数据
        if(!CollectionUtils.isEmpty(keys)) {
            //删除缓存数据
            redisTemplate.delete(keys);
        }

        return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"修改sku成功");
    }


    @Override
    public JsonVO<PageDTO<CommoditySkuDto>> queryCommoditySku(GoodsSkuQuery query) {
        String key = RedisTool.GOODS_SKU_LIST_ID;
        PageDTO<CommoditySkuDto>  commoditySkuDtoPageDTO= new PageDTO<>();
        //缓存列表
        List<CommoditySkuDto> commoditySkuDtoList = new ArrayList<>();
        if(StrUtil.isNotEmpty(query.getGoodsName())) {
            key += query.getGoodsName();
        }else {
            key += "page";
        }
        String jsonGet = JSONUtil.toJsonStr(redisTemplate.opsForValue().get(key));
        commoditySkuDtoList = JSONUtil.toList(jsonGet, CommoditySkuDto.class);
        int count = flyGoodsSkuMapper.querySkuCount(query);
        if(count < 1){
            return JsonVO.create(commoditySkuDtoPageDTO,ResultStatus.SUCCESS.getCode(),"相关数据为空");
        }
        if(CollectionUtils.isEmpty(commoditySkuDtoList)){
            commoditySkuDtoList = flyGoodsSkuMapper.querySku(query);

            if(!CollectionUtils.isEmpty(commoditySkuDtoList)){
                //缓存列表
                String jsonStr = JSONUtil.toJsonStr(commoditySkuDtoList);
                redisTemplate.opsForValue().set(key,jsonStr);
            }
        }
        commoditySkuDtoPageDTO.setPageIndex(query.getPageIndex());
        commoditySkuDtoPageDTO.setPageSize(query.getPageSize());
        commoditySkuDtoPageDTO.setTotal((long) count);
        long pages = (count + query.getPageIndex() - 1) / query.getPageSize();
        commoditySkuDtoPageDTO.setPages(pages);
        commoditySkuDtoPageDTO.setRows(commoditySkuDtoList);
        return JsonVO.success(commoditySkuDtoPageDTO);
    }

    @Override
    public JsonVO<Boolean> removeCommoditySku(List<Integer> commoditySkuIdList) {

        QueryWrapper<FlyGoodsSku> queryWrapper = new QueryWrapper<>();
        queryWrapper.in("sku_id",commoditySkuIdList);
        int delete = flyGoodsSkuMapper.delete(queryWrapper);
        if(delete <= 0){
            throw new RuntimeException("SKU数据删除失败!");
        }

        Set<String> keys = redisTemplate.keys(RedisTool.GOODS_SKU_LIST_ID + "*");
        if(!CollectionUtils.isEmpty(keys)) {
            //删除缓存数据
            redisTemplate.delete(keys);
        }

        return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"删除sku成功");
    }
}
