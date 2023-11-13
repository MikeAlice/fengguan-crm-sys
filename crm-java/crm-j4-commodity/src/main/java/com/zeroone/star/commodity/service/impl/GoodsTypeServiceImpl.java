package com.zeroone.star.commodity.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.OrderItem;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoodsAttr;
import com.zeroone.star.commodity.entity.FlyGoodsAttrValue;
import com.zeroone.star.commodity.mapper.FlyGoodsAttrMapper;
import com.zeroone.star.commodity.mapper.FlyGoodsAttrValueMapper;
import com.zeroone.star.commodity.mapper.GoodsTypeMapper;
import com.zeroone.star.commodity.service.GoodsTypeService;
import com.zeroone.star.commodity.service.IFlyGoodsAttrService;
import com.zeroone.star.commodity.service.IFlyGoodsAttrValueService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.AddNewTypeDTO;
import com.zeroone.star.project.dto.j4.commodity.AddTypeDTO;
import com.zeroone.star.project.dto.j4.commodity.DetailedTypeInfoDTO;
import com.zeroone.star.project.dto.j4.commodity.ModifyTypeDTO;
import com.zeroone.star.project.vo.j4.commodity.DetailedTypeVO;
import com.zeroone.star.project.vo.j4.commodity.SimpleTypeVO;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.time.Duration;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

/**
 * @author Ak5ma1
 */
@Service
public class GoodsTypeServiceImpl implements GoodsTypeService {

    @Resource
    RedisTemplate<String,Object> redisTemplate;
    @Resource
    GoodsTypeMapper goodsTypeMapper;
    @Override
    public PageDTO<SimpleTypeVO> findSimpleType( long pageNum,  long pageSize) {
        Page<SimpleTypeVO> page=new Page<>(pageNum,pageSize);
        page.addOrder(OrderItem.desc("sort"));
        List<FlyGoodsAttr> pagedDTORes = goodsTypeMapper.findPages(page);
        List<SimpleTypeVO> pagedRes = new ArrayList<>();
        pagedDTORes.forEach(pagedDTORe->{
            SimpleTypeVO simpleTypeVO=new SimpleTypeVO();
            simpleTypeVO.setAttrId(pagedDTORe.getAttrId());
            simpleTypeVO.setSort(pagedDTORe.getSort());
            simpleTypeVO.setVisible(pagedDTORe.getVisible());
            simpleTypeVO.setAttrName(pagedDTORe.getAttrName());
            pagedRes.add(simpleTypeVO);
        });
        pagedRes.forEach(simpleTypeVO -> {
            int attrId = simpleTypeVO.getAttrId();
            simpleTypeVO.setAttrValueName(goodsTypeMapper.findAllTags(attrId));
        });
        page.setRecords(pagedRes);
        return PageDTO.create(page);
    }
    @Resource
    IFlyGoodsAttrService attrService;
    @Resource
    IFlyGoodsAttrValueService valueService;
    private static final String detailedKeyPrefix="goods_attr_detailed_";
    @Override
    public DetailedTypeVO findDetailedType(int attrId) {
        String key=detailedKeyPrefix+attrId;
        if(Boolean.TRUE.equals(redisTemplate.hasKey(key))) {
            redisTemplate.expire(key, Duration.ofMinutes(1));
            return (DetailedTypeVO) redisTemplate.opsForValue().get(key);
        }
        Page<FlyGoodsAttrValue> page=new Page<>();
        page.addOrder(OrderItem.desc("sort"));
        DetailedTypeVO detailedTypeVO=new DetailedTypeVO();
        QueryWrapper<FlyGoodsAttr> AttrWrapper = new QueryWrapper<FlyGoodsAttr>().
                select("attr_name", "visible", "sort").eq("attr_id", attrId);
        FlyGoodsAttr flyGoodsAttr = attrService.getOne(AttrWrapper);
        if (flyGoodsAttr==null) return null;
        List<FlyGoodsAttrValue> flyGoodsAttrValue = valueService.query().
                select("attr_value_id", "attr_value_name", "attr_value_data", "type", "sort", "is_search").
                eq("attr_id", attrId).orderByDesc("sort").list();
//        System.out.println("flyGoodsAttrValue = " + flyGoodsAttrValue);
        List<DetailedTypeInfoDTO> detailedTypeInfoDTO = new ArrayList<>();
        if (flyGoodsAttrValue==null||flyGoodsAttrValue.isEmpty()) return null;
        flyGoodsAttrValue.forEach(flyGoodsAttrValue1 -> {
            DetailedTypeInfoDTO typeInfoDTO=new DetailedTypeInfoDTO();
            typeInfoDTO.setType(flyGoodsAttrValue1.getType());
            typeInfoDTO.setSort(flyGoodsAttrValue1.getSort());
            if (flyGoodsAttrValue1.getSearch()) typeInfoDTO.setSearch(1);
            else typeInfoDTO.setSearch(0);
            typeInfoDTO.setAttrValueId(flyGoodsAttrValue1.getAttrValueId());
            typeInfoDTO.setAttrValueName(flyGoodsAttrValue1.getAttrValueName());
            typeInfoDTO.setAttrValueData(flyGoodsAttrValue1.getAttrValueData());
            typeInfoDTO.setAttrId(attrId);
            detailedTypeInfoDTO.add(typeInfoDTO);
        });
        detailedTypeVO.setDetailedTypeInfoDTOList(detailedTypeInfoDTO);
        detailedTypeVO.setAttrName(flyGoodsAttr.getAttrName());
        detailedTypeVO.setVisible(flyGoodsAttr.getVisible());
        detailedTypeVO.setSort(flyGoodsAttr.getSort());
        detailedTypeVO.setAttrId(attrId);
        redisTemplate.opsForValue().set(key,detailedTypeVO);
        return detailedTypeVO;
    }
    @Resource
    FlyGoodsAttrMapper attrMapper;
    @Override
    public Boolean deleteType(int attrId) {
        String key=detailedKeyPrefix+attrId;
        if(Boolean.TRUE.equals(redisTemplate.hasKey(key))) {
            redisTemplate.delete(key);
        }
        QueryWrapper<FlyGoodsAttrValue> attrValueQueryWrapper=
                new QueryWrapper<FlyGoodsAttrValue>().eq("attr_id",attrId);
        int ValueCnt = attrValueMapper.delete(attrValueQueryWrapper);
        int attrCnt = attrMapper.deleteById(attrId);
        return ValueCnt != 0 || attrCnt != 0;
    }

    @Resource
    FlyGoodsAttrValueMapper attrValueMapper;
    @Override
    public Boolean deleteTypeAttr(int attrValueId) {
        int deletedRes = attrValueMapper.deleteById(attrValueId);
        return deletedRes != 0;
    }

    @Override
    public Boolean modifyTypeAttr(ModifyTypeDTO modifyTypeDTO) {
        //修改类型列表信息
        QueryWrapper<FlyGoodsAttr> flyGoodsAttrQueryWrapper=
                new QueryWrapper<FlyGoodsAttr>()
                        .select("attr_name","visible","sort","modify_time")
                        .eq("attr_id",modifyTypeDTO.getAttrId());
        String key=detailedKeyPrefix+modifyTypeDTO.getAttrId();
        if(Boolean.TRUE.equals(redisTemplate.hasKey(key))) {
            redisTemplate.delete(key);
        }
        FlyGoodsAttr flyGoodsAttr = new FlyGoodsAttr();
        flyGoodsAttr.setAttrId(modifyTypeDTO.getAttrId());
        flyGoodsAttr.setAttrName(modifyTypeDTO.getAttrName());
        flyGoodsAttr.setSort(modifyTypeDTO.getSort());
        flyGoodsAttr.setVisible(modifyTypeDTO.isVisible());
        flyGoodsAttr.setModifyTime(getTime());
        attrMapper.update(flyGoodsAttr,flyGoodsAttrQueryWrapper);
        //修改标签
        List<DetailedTypeInfoDTO> detailedTypeInfoDTOList;
        detailedTypeInfoDTOList=modifyTypeDTO.getDetailedTypeInfoDTOList();
        detailedTypeInfoDTOList.forEach(detailedTypeInfoDTO -> {
            FlyGoodsAttrValue goodsAttrValue=new FlyGoodsAttrValue();
            QueryWrapper<FlyGoodsAttrValue> queryWrapper=
                    new QueryWrapper<>();
            queryWrapper.select("attr_value_name","attr_value_data","type",
                            "sort","is_search")
                    .eq("attr_value_id",detailedTypeInfoDTO.getAttrValueId());
            goodsAttrValue.setAttrValueData(detailedTypeInfoDTO.getAttrValueData());
            goodsAttrValue.setType(detailedTypeInfoDTO.getType());
            goodsAttrValue.setSearch(detailedTypeInfoDTO.getSearch() == 1);
            goodsAttrValue.setSort(detailedTypeInfoDTO.getSort());
            goodsAttrValue.setAttrValueName(detailedTypeInfoDTO.getAttrValueName());
            attrValueMapper.update(goodsAttrValue,queryWrapper);
        });
        //新增标签
        List<AddTypeDTO> detailedTypeToAddList=modifyTypeDTO.getDetailedTypeToAddList();
        detailedTypeToAddList.forEach(addTypeDTO -> {
            FlyGoodsAttrValue goodsAttrValue=new FlyGoodsAttrValue();
            QueryWrapper<FlyGoodsAttrValue> queryWrapper=
                    new QueryWrapper<FlyGoodsAttrValue>().select("attr_value_id")
                                    .orderByDesc("attr_value_id").last("limit 1");
            Integer attrValueId = attrValueMapper.selectOne(queryWrapper).getAttrValueId()+1;
            goodsAttrValue.setAttrValueId(attrValueId);
            goodsAttrValue.setAttrId(addTypeDTO.getAttrId());
            goodsAttrValue.setType(addTypeDTO.getType());
            goodsAttrValue.setSort(addTypeDTO.getSort());
            goodsAttrValue.setSearch(addTypeDTO.getSearch()==1);
            goodsAttrValue.setAttrValueName(addTypeDTO.getAttrValueName());
            goodsAttrValue.setAttrValueData(addTypeDTO.getAttrValueData());
            attrValueMapper.insert(goodsAttrValue);
        });
        //删除对应字段
        int[] attrValueIdsToDelete=modifyTypeDTO.getAttrValueIdsToDelete();
        for (int attrValueId : attrValueIdsToDelete) {
            deleteTypeAttr(attrValueId);
        }
        return true;
    }

    @Override
    public Boolean addType(AddNewTypeDTO addNewTypeDTO) {
        FlyGoodsAttr flyGoodsAttr=new FlyGoodsAttr();
        BeanUtil.copyProperties(addNewTypeDTO,flyGoodsAttr);
        System.out.println(flyGoodsAttr);
        Integer time=getTime();
        flyGoodsAttr.setCreateTime(time);
        flyGoodsAttr.setModifyTime(time);
        //===========================================================
//        flyGoodsAttr.setVisible(addNewTypeDTO.isVisible());
//        flyGoodsAttr.setSort(addNewTypeDTO.getSort());
//        flyGoodsAttr.setAttrName(addNewTypeDTO.getAttrName());
        QueryWrapper<FlyGoodsAttr> queryWrapper=
                new QueryWrapper<FlyGoodsAttr>().select("attr_id")
                        .orderByDesc("attr_id").last("limit 1");
        Integer attrId = attrMapper.selectOne(queryWrapper).getAttrId()+1;
        flyGoodsAttr.setAttrId(attrId);
        int insert1 = attrMapper.insert(flyGoodsAttr);
        int insert;
        List<AddTypeDTO> attrLists = addNewTypeDTO.getDetailedTypeToAddList();
        attrLists.forEach(addTypeDTO -> {
            FlyGoodsAttrValue goodsAttrValue=new FlyGoodsAttrValue();
            QueryWrapper<FlyGoodsAttrValue> attrQueryWrapper=
                    new QueryWrapper<FlyGoodsAttrValue>().select("attr_value_id")
                            .orderByDesc("attr_value_id").last("limit 1");
            Integer attrValueId = attrValueMapper.selectOne(attrQueryWrapper).getAttrValueId()+1;
            BeanUtil.copyProperties(addTypeDTO,goodsAttrValue);
            goodsAttrValue.setAttrValueId(attrValueId);
            goodsAttrValue.setAttrId(attrId);
//            goodsAttrValue.setType(addTypeDTO.getType());
//            goodsAttrValue.setSort(addTypeDTO.getSort());
            goodsAttrValue.setSearch(addTypeDTO.getSearch()==1);
//            goodsAttrValue.setAttrValueName(addTypeDTO.getAttrValueName());
//            goodsAttrValue.setAttrValueData(addTypeDTO.getAttrValueData());
             attrValueMapper.insert(goodsAttrValue);
        });
//        DetailedTypeVO detailedTypeVO=new DetailedTypeVO();
//        BeanUtil.copyProperties(addNewTypeDTO,detailedTypeVO);
//        detailedTypeVO.setDetailedTypeInfoDTOList();
////        redisTemplate.opsForValue().set(k);
        return insert1!=0;
    }

    private Integer getTime(){
        Calendar calendar=Calendar.getInstance();
        SimpleDateFormat simpleDateFormat=new SimpleDateFormat("yyyyMMddHH");
        String format = simpleDateFormat.format(calendar.getTime());
        System.out.println("format = " + format);
        int i = Integer.parseInt(format.trim());
        return (int)i;
    }
}
