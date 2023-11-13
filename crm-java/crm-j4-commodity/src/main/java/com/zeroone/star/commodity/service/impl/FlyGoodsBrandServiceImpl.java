package com.zeroone.star.commodity.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.CollectionUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.commodity.entity.FlyGoodsBrand;
import com.zeroone.star.commodity.mapper.FlyGoodsBrandMapper;
import com.zeroone.star.commodity.service.IFlyGoodsBrandService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.commodity.BrandDTO;
import com.zeroone.star.project.query.j4.commodity.BrandQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.BeanUtils;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 品牌表 服务实现类
 * </p>
 *
 * @author diwu
 * @since 2023-10-23
 */
@Service
public class FlyGoodsBrandServiceImpl extends ServiceImpl<FlyGoodsBrandMapper, FlyGoodsBrand> implements IFlyGoodsBrandService {

    @Resource
    FlyGoodsBrandMapper flyGoodsBrandMapper;

    @Resource
    private StringRedisTemplate stringRedisTemplate;

    @Override
    public PageDTO<BrandDTO> listAll(BrandQuery query) {
        // 构建分页查询对象
        Page<FlyGoodsBrand> brandPage = new Page<>(query.getPageIndex(), query.getPageSize());

        // 构建查询条件
        QueryWrapper<FlyGoodsBrand> wrapper = new QueryWrapper<>();
        if (query.getBrandName() != null) {
            wrapper.like("brand_name", query.getBrandName());
        }
        if (query.getBrandInitial() != null) {
            wrapper.eq("brand_initial", query.getBrandInitial());
        }

        // 执行查询
        Page<FlyGoodsBrand> flyGoodsBrandPage = baseMapper.selectPage(brandPage, wrapper);

        // 将查询结果转换为DTO对象
        List<BrandDTO> brandDTOList = new ArrayList<>();
        List<FlyGoodsBrand> brandList = flyGoodsBrandPage.getRecords();
        if (!CollectionUtils.isEmpty(brandList)) {
            for (FlyGoodsBrand brand : brandList) {
                BrandDTO brandDTO = new BrandDTO();
                BeanUtils.copyProperties(brand, brandDTO);
                brandDTOList.add(brandDTO);
            }
        }

        // 封装分页查询结果DTO对象
        PageDTO<BrandDTO> pageDTO = new PageDTO<>();
        pageDTO.setTotal(flyGoodsBrandPage.getTotal());
        pageDTO.setPageIndex(flyGoodsBrandPage.getCurrent());
        pageDTO.setPages(flyGoodsBrandPage.getPages());
        pageDTO.setRows(brandDTOList);
        return pageDTO;

    }

    @Override
    @Transactional
    public boolean addBrand(BrandDTO dto) {
        //根据品牌名字查寻数据库，判断是否有该品牌
        QueryWrapper<FlyGoodsBrand> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("brand_name",dto.getBrandName());
        Long count = flyGoodsBrandMapper.selectCount(queryWrapper);
        if(count > 0){
            return false;
        }
        //没有查询到相同品牌,执行添加操作
        FlyGoodsBrand brand = BeanUtil.copyProperties(dto, FlyGoodsBrand.class);
        int rows = flyGoodsBrandMapper.insert(brand);
        return rows > 0;
    }

    @Override
    @Transactional
    public boolean updateBrand( BrandDTO dto) {

        // 创建 QueryWrapper 对象
        QueryWrapper<FlyGoodsBrand> queryWrapper = Wrappers.query();
        queryWrapper.eq("brand_id", dto.getBrandId());

        // 调用查询方法，返回符合条件的品牌信息
        FlyGoodsBrand brand = flyGoodsBrandMapper.selectOne(queryWrapper);
        if (brand == null) {
            return  false;
        }
        BeanUtil.copyProperties(dto, FlyGoodsBrand.class);
        int rows = flyGoodsBrandMapper.updateById(brand);
        return rows > 0;
    }


    @Override
    @Transactional
    public boolean deleteBrand(int commodityBrandId) {
//        // 先查询出要删除的品牌信息
//        FlyGoodsBrand brand = flyGoodsBrandMapper.selectById(commodityBrandId);
//        if (brand == null) {
//            throw new RuntimeException("Brand not found");
//        }
        // 删除品牌
        int deleteCount = flyGoodsBrandMapper.deleteById(commodityBrandId);
        if (deleteCount <= 0) {
            return false;
        }
        return true;
    }
}
