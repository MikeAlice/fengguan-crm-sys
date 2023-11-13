package com.zeroone.star.commodity.service.impl;


import cn.hutool.core.bean.BeanUtil;
import com.alibaba.nacos.client.naming.utils.CollectionUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoodsSpec;
import com.zeroone.star.commodity.mapper.FlyGoodsSpecMapper;
import com.zeroone.star.commodity.service.IFlyGoodsSpecService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.SpecDTO;
import com.zeroone.star.project.query.j4.commodity.CommoditySpecQuery;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.validation.annotation.Validated;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 商品属性（规格）表 服务实现类
 * </p>
 *
 * @author Tezz
 * @since 2023-10-25
 */

@Mapper(componentModel = "spring")
interface MsSampleStruct {
    SpecDTO sdoToSDto(FlyGoodsSpec flyGoodsSpec);

}
@Service
@Validated
public class FlyGoodsSpecServiceImpl extends ServiceImpl<FlyGoodsSpecMapper, FlyGoodsSpec> implements IFlyGoodsSpecService {

    @Resource
    MsSampleStruct msSampleStruct;

    @Resource
    FlyGoodsSpecMapper flyGoodsSpecMapper;

    @Override
    public PageDTO<SpecDTO> queryAll(CommoditySpecQuery query) {
        Page<FlyGoodsSpec> FlyGoodsSpecPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FlyGoodsSpec> wrapper = new QueryWrapper<>();
//        wrapper.like(StringUtils.isNotBlank(query.getSpecName()),"spec_name", query.getSpecName())
//        wrapper.select("spec_name","spec_id","visible","sort","spec_des")
//                .eq("status","1")
//                .like("spec_id",query.getSpecId())
//                .like("spec_name", query.getSpecName())
//               .like("visible", query.getVisible())
//                .like("sort", query.getSort())
//                .like("spec_des", query.getSpecDes());
        if (query.getSpecName() != null) {
            wrapper.like("spec_name", query.getSpecName());
        }

        // 执行查询
        Page<FlyGoodsSpec> result = baseMapper.selectPage(FlyGoodsSpecPage, wrapper);

        // 将查询结果转换为DTO对象
        List<SpecDTO> specDTOList = new ArrayList<>();
        List<FlyGoodsSpec> specList = result.getRecords();
        if (!CollectionUtils.isEmpty(specList)) {
            for (FlyGoodsSpec spec : specList) {
                SpecDTO specDTO = new SpecDTO();
                BeanUtils.copyProperties(spec, specDTO);
                specDTOList.add(specDTO);
            }
        }

        // 封装分页查询结果DTO对象
        PageDTO<SpecDTO> pageDTO = new PageDTO<>();
        pageDTO.setTotal(result.getTotal());
        pageDTO.setPageIndex(result.getCurrent());
        pageDTO.setPages(result.getPages());
        pageDTO.setRows(specDTOList);
        return pageDTO;



//        return PageDTO.create(result, src -> msSampleStruct.sdoToSDto(src));
    }

    @Override
    public boolean modifyData(SpecDTO specDTO) {
//        FlyGoodsSpec flyGoodsSpec = new FlyGoodsSpec();
//        QueryWrapper<FlyGoodsSpec> wrapper = new QueryWrapper<>();
//        wrapper.eq("spec_id",specDTO.getSpecId());
//        flyGoodsSpec.setSpecId(specDTO.getSpecId());
//        BeanUtil.copyProperties(specDTO, flyGoodsSpec);
//        int update = flyGoodsSpecMapper.updateById(flyGoodsSpec);

        // 创建 QueryWrapper 对象
        //QueryWrapper<FlyGoodsSpec> queryWrapper = Wrappers.query();
        QueryWrapper<FlyGoodsSpec> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("spec_id", specDTO.getSpecId());

        // 调用查询方法，返回符合条件的规格信息
        FlyGoodsSpec flyGoodsSpec = flyGoodsSpecMapper.selectOne(queryWrapper);
        if (flyGoodsSpec == null) {
            return false;
        }
//        BeanUtil.copyProperties(specDTO, FlyGoodsSpec.class);
        int rows = flyGoodsSpecMapper.updateById(BeanUtil.copyProperties(specDTO, FlyGoodsSpec.class));
        return rows > 0;

//        if(update == 0){
//            return JsonVO.fail(false);
//        }
//        return JsonVO.success(true);
    }

    @Override
    public boolean deleteData(int specId) {
//       FlyGoodsSpec flyGoodsSpec = new FlyGoodsSpec();
//        BeanUtil.copyProperties(specDTO, flyGoodsSpec);
//        int delete = flyGoodsSpecMapper.deleteById(flyGoodsSpec);
//
//        if(delete == 0){
//            return JsonVO.fail(false);
//        }
//
//        return JsonVO.success(true);
        // 删除品牌
        int deleteCount = flyGoodsSpecMapper.deleteById(specId);
        if (deleteCount <= 0) {
            return false;
        }
        return true;
    }

    @Override
    public boolean addData(SpecDTO specDTO) {
//        FlyGoodsSpec flyGoodsSpec = new FlyGoodsSpec();
//        BeanUtil.copyProperties(specDTO, flyGoodsSpec);
//        int insert = flyGoodsSpecMapper.insert(flyGoodsSpec);
//
//        if(insert == 0){
//            return JsonVO.fail(false);
//        }
//
//        return JsonVO.success(true);
        //根据规格名字查寻数据库，判断是否有该规格
        QueryWrapper<FlyGoodsSpec> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("spec_name",specDTO.getSpecName());
        Long count = flyGoodsSpecMapper.selectCount(queryWrapper);
        if(count > 0){
            return false;
        }
        //没有查询到相同规格,执行添加操作
        FlyGoodsSpec spec = BeanUtil.copyProperties(specDTO, FlyGoodsSpec.class);
        int rows = flyGoodsSpecMapper.insert(spec);
        return rows > 0;


    }
}
