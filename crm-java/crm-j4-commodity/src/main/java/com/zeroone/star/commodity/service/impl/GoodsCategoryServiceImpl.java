package com.zeroone.star.commodity.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoodsCategory;
import com.zeroone.star.commodity.mapper.FlyGoodsCategoryMapper;
import com.zeroone.star.commodity.service.GoodsCategoryService;
import com.zeroone.star.commodity.tools.RedisTool;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.AddGoodsCategoryDTO;
import com.zeroone.star.project.dto.j4.commodity.CategoryNameTreeDTO;
import com.zeroone.star.project.dto.j4.commodity.StructTreeDTO;
import com.zeroone.star.project.dto.j4.commodity.UpdateGoodsCategoryDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.*;

/**
 * @author 张二发
 */
@Service
public class GoodsCategoryServiceImpl implements GoodsCategoryService {
    @Resource
    private FlyGoodsCategoryMapper goodsCategoryMapper;
    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    /**
     * 使用redis维护商品分类名称和简称的set添加前先查询商品分类名称和简称是否已近存在，
     * 存在则向前端放回名称已存在，不存在则向数据库添加数据，并把商品分类名称和简称添加到redis set中
     * @param goodsCategoryDTO 商品分类
     * @return
     */
    @Override
    public JsonVO<Boolean> saveGoodsCategory(AddGoodsCategoryDTO goodsCategoryDTO) {
        // 判断商品分类名称是否存在
        Boolean nameExist = redisTemplate.opsForSet().isMember(RedisTool.GOODS_CATEGORY_NAME_SET_KEY,
                goodsCategoryDTO.getName());
        if (Boolean.TRUE.equals(nameExist)){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),
                    "商品分类名称已存在");
        }
        // 判断商品分类简称是否存在
        Boolean shortNameExist = redisTemplate.opsForSet().isMember(RedisTool.GOODS_CATEGORY_SHORT_NAME_KEY,
                goodsCategoryDTO.getShortName());
        if (Boolean.TRUE.equals(shortNameExist)){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),
                    "商品分类简称已存在");
        }
        // 将商品分类保存到数据库
        // TODO:DTO转DO
        goodsCategoryMapper.insert(new FlyGoodsCategory(goodsCategoryDTO));
        // 将商品分类名称和简称保存到redis
        redisTemplate.opsForSet().add(RedisTool.GOODS_CATEGORY_NAME_SET_KEY,
                goodsCategoryDTO.getName());
        redisTemplate.opsForSet().add(RedisTool.GOODS_CATEGORY_SHORT_NAME_KEY,
                goodsCategoryDTO.getShortName());
        // 新增商品分类时，将商品分类名称树从redis中删除
        redisTemplate.delete(RedisTool.GOODS_CATEGORY_NAME_TREE_KEY);
        // TODO:新增商品分类时，将商品分类名称结构树从redis中删除
        // 新增商品分类时，将商品分类列表从redis中删除
        redisTemplate.delete(RedisTool.getGoodsCategoryListKey(1, 10));
        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(),
                "商品分类保存成功");
    }

    /**
     * 删除商品分类
     * 1. 判断要删除的商品分类是否存在
     * 2. 判断商品分类下是否有商品，有商品则不能删除，没有商品则删除商品分类
     * @param goodsCategoryId 商品分类id
     * @return 删除结果
     */
    @Override
    public JsonVO<Boolean> removeGoodsCategory(int goodsCategoryId) {
        // 判断商品分类是否在redis中缓存
        FlyGoodsCategory goodsCategory = (FlyGoodsCategory) redisTemplate.opsForValue().get(
                RedisTool.getGoodsCategoryKey(goodsCategoryId));
        if (goodsCategory == null){
            // 从数据库中查询商品分类
            goodsCategory = goodsCategoryMapper.selectById(goodsCategoryId);
            if (goodsCategory == null){
                return JsonVO.create(null, ResultStatus.FAIL.getCode(),
                        "商品分类不存在");
            }
        }
        // TODO:判断商品分类下是否有商品（商品service中未找到相关接口）
        // 删除该分类及其下的所有子分类
        deleteCategoryOnDB(goodsCategoryId);
        // 从redis中删除商品分类
        redisTemplate.delete(RedisTool.getGoodsCategoryKey(goodsCategoryId));
        // 从redis set中删除商品分类名称和简称
        redisTemplate.opsForSet().remove(RedisTool.GOODS_CATEGORY_NAME_SET_KEY,
                goodsCategory.getCategoryName());
        redisTemplate.opsForSet().remove(RedisTool.GOODS_CATEGORY_SHORT_NAME_KEY,
                goodsCategory.getShortName());
        // 删除商品分类时，将商品分类名称树从redis中删除
        redisTemplate.delete(RedisTool.GOODS_CATEGORY_NAME_TREE_KEY);
        // 删除商品分类时，将商品分类列表从redis中删除
        redisTemplate.delete(RedisTool.getGoodsCategoryListKey(1, 10));
        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(),
                "商品分类删除成功");
    }

    /**
     * 从数据库中删除商品分类
     * @param goodsCategoryId
     */
    private void deleteCategoryOnDB(int goodsCategoryId){
        // 查询该分类下有哪些子分类
        List<FlyGoodsCategory> childrenCategoryList = goodsCategoryMapper.selectByParentId(goodsCategoryId);
        // 递归删除子分类
        for (FlyGoodsCategory childrenCategory : childrenCategoryList){
            deleteCategoryOnDB(childrenCategory.getCategoryId());
        }
        // 从数据库中删除商品分类
        goodsCategoryMapper.deleteById(goodsCategoryId);
    }

    /**
     * 修改商品分类
     * 1. 判断要修改的商品分类是否存在
     * 2. 如果要修改商品分类的名称、简称，则判断修改后的名称、简称是否已经存在
     * 3. 修改商品分类
     * @param goodsCategoryDTO 商品分类
     * @return 修改结果
     */
    @Override
    public JsonVO<Boolean> modifyGoodsCategory(UpdateGoodsCategoryDTO goodsCategoryDTO) {
        // 判断商品分类是否存在
        FlyGoodsCategory goodsCategory = getCategoryFromRedisOrDb(goodsCategoryDTO.getId());
        if (goodsCategory == null){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),
                    "商品分类不存在");
        }
        // 如果商品分类要修改名称，则判断修改后的名称是否已经存在
        if (goodsCategoryDTO.getName() != null){
            if (!goodsCategory.getCategoryName().equals(goodsCategoryDTO.getName()) &&
                    Boolean.TRUE.equals(redisTemplate.opsForSet().isMember(RedisTool.GOODS_CATEGORY_NAME_SET_KEY,
                            goodsCategoryDTO.getName()))){
                return JsonVO.create(null, ResultStatus.FAIL.getCode(),
                        "商品分类名称已存在");
            }
        }
        // 如果商品分类要修改简称，则判断修改后的简称是否已经存在
        if (goodsCategoryDTO.getShortName() != null){
            if (!goodsCategory.getShortName().equals(goodsCategoryDTO.getShortName()) &&
                    Boolean.TRUE.equals(redisTemplate.opsForSet().isMember(RedisTool.GOODS_CATEGORY_SHORT_NAME_KEY,
                    goodsCategoryDTO.getShortName()))){
                return JsonVO.create(null, ResultStatus.FAIL.getCode(),
                        "商品分类简称已存在");
            }
        }
        // 修改商品分类
        // TODO:DTO转DO
        goodsCategoryMapper.updateById(new FlyGoodsCategory(goodsCategoryDTO));
        // 修改商品分类时如果修改了商品分类名称，将商品分类名称树从redis中删除
        if (goodsCategoryDTO.getName() != null){
            redisTemplate.delete(RedisTool.GOODS_CATEGORY_NAME_TREE_KEY);
        }
        // TODO:修改商品分类时如果修改了商品分类名称，将商品分类名称结构树从redis中删除
        // 修改商品分类时如果修改了商品分类名称，将商品分类列表从redis中删除
        redisTemplate.delete(RedisTool.getGoodsCategoryListKey(1, 10));
        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(),
                "商品分类修改成功");
    }

    @Override
    public UpdateGoodsCategoryDTO getGoodsCategory(int goodsCategoryId) {
        // 查询商品分类
        FlyGoodsCategory goodsCategory = getCategoryFromRedisOrDb(goodsCategoryId);
        // TODO:DO转DTO
        return new UpdateGoodsCategoryDTO(goodsCategory.getCategoryId(),
                goodsCategory.getCategoryName(), goodsCategory.getShortName(),
                goodsCategory.getParentId(), goodsCategory.getSort(),
                goodsCategory.getDescription(),
                goodsCategory.getKeywords(), goodsCategory.getVisible());
    }

    /**
     * 从redis或数据库中查询商品分类
     * 如果redis中不存在，则从数据库中查询，并将查询结果保存到redis中
     * @param goodsCategoryId
     * @return
     */
    private FlyGoodsCategory getCategoryFromRedisOrDb(int goodsCategoryId){
        // redis中查询商品分类
        FlyGoodsCategory goodsCategory = (FlyGoodsCategory) redisTemplate.opsForValue().get(
                RedisTool.getGoodsCategoryKey(goodsCategoryId));
        if (goodsCategory == null){
            // 从数据库中查询商品分类
            goodsCategory = goodsCategoryMapper.selectById(goodsCategoryId);
            if (goodsCategory == null){
                return null;
            }
            // 将商品分类保存到redis
            redisTemplate.opsForValue().set(RedisTool.getGoodsCategoryKey(goodsCategoryId),
                    goodsCategory);
        }
        return goodsCategory;
    }

    @Override
    public List<CategoryNameTreeDTO> listCategoryNameTree() {
        // 从redis中查询商品分类名称树
        List<CategoryNameTreeDTO> categoryNameTreeList = (List<CategoryNameTreeDTO>) redisTemplate.opsForValue().get(
                RedisTool.GOODS_CATEGORY_NAME_TREE_KEY);
        if (categoryNameTreeList == null){
            // 从数据库中查询商品分类名称树
            categoryNameTreeList = listCategoryNameTreeFromDb();
            // 将商品分类名称树保存到redis
            redisTemplate.opsForValue().set(RedisTool.GOODS_CATEGORY_NAME_TREE_KEY,
                    categoryNameTreeList);
        }
        return categoryNameTreeList;
    }

    /**
     * 从数据库中查询商品分类名称树
     * @return
     */
    private List<CategoryNameTreeDTO> listCategoryNameTreeFromDb(){
        // 查询所有商品分类数据
        List<FlyGoodsCategory> goodsCategoryList = goodsCategoryMapper.selectList(null);
        // 将商品分类数据转换为商品分类名称树
        // 用map保存商品分类名称树，key为商品分类id，value为商品分类名称树
        Map<Integer, CategoryNameTreeDTO> map = new HashMap<>();
        // 一级分类集合
        List<CategoryNameTreeDTO> firstLevelCategoryList = new LinkedList<>();
        for (FlyGoodsCategory goodsCategory : goodsCategoryList){
            if (!map.containsKey(goodsCategory.getCategoryId())) {
                map.put(goodsCategory.getCategoryId(), new CategoryNameTreeDTO(
                        goodsCategory.getCategoryId(), goodsCategory.getCategoryName()));
            }
            // 如果商品分类是一级分类，则将商品分类添加到一级分类集合中
            if (goodsCategory.getParentId() == 0){
                firstLevelCategoryList.add(map.get(goodsCategory.getCategoryId()));
            }
        }
        // 将子分类添加到父分类的children中
        for (FlyGoodsCategory goodsCategory : goodsCategoryList){
            if (goodsCategory.getParentId() != 0){
                if (!map.containsKey(goodsCategory.getParentId())){
                    System.out.println("商品分类数据异常，父分类不存在");
                    continue;
                }
                map.get(goodsCategory.getParentId()).getChildren().add(map.get(goodsCategory.getCategoryId()));
            }
        }
        // 将商品分类名称树添加到list中返回
        return firstLevelCategoryList;
    }

    @Override
    public PageDTO<FlyGoodsCategory> listGoodsCategory(int pageNum, int pageSize) {
        // 从redis中查询商品分类列表
        PageDTO<FlyGoodsCategory> goodsCategoryPageDTO = (PageDTO<FlyGoodsCategory>) redisTemplate.opsForValue().get(
                RedisTool.getGoodsCategoryListKey(pageNum, pageSize));
        if (goodsCategoryPageDTO == null){
            // 从数据库中查询商品分类列表
            Page<FlyGoodsCategory> flyGoodsCategoryPage = goodsCategoryMapper.selectPage(new Page<>(pageNum, pageSize), null);
            // 将商品分类列表保存到PageDTO中
            goodsCategoryPageDTO = PageDTO.create(flyGoodsCategoryPage);
            // 将商品分类列表保存到redis
            redisTemplate.opsForValue().set(RedisTool.getGoodsCategoryListKey(pageNum, pageSize),
                    goodsCategoryPageDTO);
        }
        return goodsCategoryPageDTO;
    }
}
