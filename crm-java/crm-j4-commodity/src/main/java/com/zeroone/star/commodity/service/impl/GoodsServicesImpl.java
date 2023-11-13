package com.zeroone.star.commodity.service.impl;

import cn.hutool.core.util.ObjectUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.commodity.entity.FlyGoods;
import com.zeroone.star.commodity.entity.FlyGoodsCategory;
import com.zeroone.star.commodity.mapper.FlyGoodsCategoryMapper;
import com.zeroone.star.commodity.mapper.GoodsMapper;
import com.zeroone.star.commodity.service.GoodsService;
import com.zeroone.star.project.dto.j4.commodity.GoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.RecommendDTO;
import com.zeroone.star.project.dto.j4.commodity.ShelfGoodsDTO;
import com.zeroone.star.project.dto.j4.commodity.validation.ContentDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author 骇客老薛
 * @date 2023/10/25 17:23
 * com.zeroone.star.commodity.service.impl
 */
@Service
public class GoodsServicesImpl implements GoodsService {

    @Autowired
    private GoodsMapper goodsMapper;

    @Autowired
    private FlyGoodsCategoryMapper goodsCategoryMapper;

    @Override
    public JsonVO<GoodsDTO> getGoodsDetailsById(Integer goodsId) {
        FlyGoods flyGoods = goodsMapper.selectById(goodsId);
        GoodsDTO goodsDTO = new GoodsDTO();
        BeanUtils.copyProperties(flyGoods,goodsDTO);
        return JsonVO.success(goodsDTO);
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public JsonVO<Boolean> addGoods(GoodsDTO goodsDTO) {
        FlyGoodsCategory flyGoodsCategory = new FlyGoodsCategory();
        flyGoodsCategory.setCategoryName(goodsDTO.getCategoryName());
        int categoryId = goodsCategoryMapper.insertCategory(flyGoodsCategory);
        if(ObjectUtil.isEmpty(categoryId)){
            throw new RuntimeException("分类插入异常");
        }
        FlyGoods flyGoods = new FlyGoods();
        flyGoods.setCategoryId(categoryId);
        flyGoods.setCreateTime(LocalDateTime.now());
        flyGoods.setSaleDate(LocalDateTime.now());
        flyGoods.setUpdateTime(LocalDateTime.now());
        BeanUtils.copyProperties(goodsDTO, flyGoods);
        int insert = goodsMapper.insert(flyGoods);

        if (insert == 0) {
            throw new RuntimeException("发布商品失败");
        }

        return JsonVO.success(true);
    }

    @Override
    public JsonVO<Boolean> isRecommend(RecommendDTO recommendDTO) {

        UpdateWrapper<FlyGoods> updateWrapper = new UpdateWrapper<>();
        updateWrapper.in("goods_id", recommendDTO.getGoodsIdList());
        updateWrapper.eq("is_recommend", recommendDTO.getIsRecommend() == 0 ? 1 : 0);
        updateWrapper.set("is_recommend", recommendDTO.getIsRecommend());

        int update = goodsMapper.update(null, updateWrapper);
        if (update == 0) {
            return JsonVO.create(false, ResultStatus.FAIL.getCode(), "没有要推荐/取消推荐的数据");
        }

        return JsonVO.create(true, ResultStatus.SUCCESS.getCode(), "修改成功");
    }

    @Override
    public JsonVO<Boolean>  modifyGoodsState(ShelfGoodsDTO shelfGoodsDTO) {

        UpdateWrapper<FlyGoods> updateWrapper = new UpdateWrapper<>();
        updateWrapper.in("goods_id", shelfGoodsDTO.getGoodsIdList());
        updateWrapper.set("state", shelfGoodsDTO.getState());

        int update = goodsMapper.update(null, updateWrapper);
        if (update == 0){
            return JsonVO.create(false, ResultStatus.FAIL.getCode(), "没有要上架/下架的商品");
        }
        return JsonVO.create(true,ResultStatus.SUCCESS.getCode(), "上架/下架成功");
    }



    @Override
    public JsonVO<Boolean> removeGoods(List<Integer> deleteGoodsIdList) {
        if (deleteGoodsIdList.size() == 0) {
            return JsonVO.create(false, ResultStatus.FAIL.getCode(), "要删除id列表为空");
        }
        goodsMapper.deleteBatchIds(deleteGoodsIdList);

        return JsonVO.create(true, ResultStatus.SUCCESS.getCode(), "删除成功");
    }

    @Override
    public JsonVO<List<String>> getGoodsNames() {
        QueryWrapper<FlyGoods> wrapper = new QueryWrapper<>();
        List<String> foodsNameList = goodsMapper.getGoodsNames();
        return JsonVO.create(foodsNameList, ResultStatus.SUCCESS.getCode(),"获取商品名称列表成功!");
    }
}
