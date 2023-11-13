package com.zeroone.star.area.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.area.entity.Area;
import com.zeroone.star.area.mapper.AreaMapper;
import com.zeroone.star.area.service.AreaService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.area.*;
import com.zeroone.star.project.query.j3.area.ObtainAreaListQuery;
import com.zeroone.star.project.query.j3.area.ObtainAreaTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.area.AreaListVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.*;

/**
 * @Description: 实现类
 * @Author: your name
 * @Date: 2023/10/24 17:38
 */
@Service
public class AreaServiceImpl extends ServiceImpl<AreaMapper, Area> implements AreaService {

    @Resource
    private RedisTemplate<String,Object> redisTemplate;

    @Autowired
    private AreaMapper areaMapper;

    /**
     * 获取区域名称结构树
     * @return  返回结果
     */
    @Override
    public List<AreaTreeInfoDTO> queryTree(ObtainAreaTreeQuery query) {
        List<AreaTreeInfoDTO> rootNodes = new ArrayList<>();
        List<Area> AreaList = lambdaQuery().orderByAsc(Area::getSort).list();
        //redis中没有数据,查询数据库
        //初始化所有根节点
        for (Area area : AreaList) {
            if (area.getParentID() == 0) {
                AreaTreeInfoDTO rootNode = new AreaTreeInfoDTO();
                BeanUtils.copyProperties(area, rootNode);
                rootNode.setLevel(1);
                rootNode.setTreeName(null);
                rootNodes.add(rootNode);
            }
        }
        //由根节点开始构建树
        for (AreaTreeInfoDTO rootNode : rootNodes) {
            buildPositionTree(rootNode, AreaList,query.getDepth());
        }
        return rootNodes;
    }

    /**
     * 获取区域列表
     * @param query 查询条件
     * @return  返回结果
     */
    @Override
    public PageDTO<AreaInfoDTO> listArea(ObtainAreaListQuery query) {
        //构建分页查询对象
        Page<Area> Page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<Area> wrapper = new QueryWrapper<>();

        //创建一个Set集合用于存储查询出来的数据的id作为分页查询条件
        Set<Integer> set = new HashSet();
        //判断pid是否为空
        if (query.getPid() != null) {
            set.add(Integer.valueOf(query.getPid()));
            //构建父节点查询条件
            QueryWrapper<Area> PidWrapper = new QueryWrapper<>();
            PidWrapper.eq("parentID", query.getPid());
            //查询父节点等于pid的所有数据
            List<Area> listArea = baseMapper.selectList(PidWrapper);
            //循环获取父节点的子节点
            while (listArea.size() != 0) {
                //创建一个临时set用于存放id
                Set<Integer> setTemp = new HashSet<>();
                //遍历列表数据
                for (Area area : listArea) {
                    //获取列表数据的id,将id作为父节点去查询子节点
                    Integer pid = area.getId();
                    set.add(pid);
                    setTemp.add(pid);
                }
                //遍历setTemp集合
                //将setTemp集合中的pid加入查询集合条件
                QueryWrapper<Area> ListWrapper = new QueryWrapper<>();
                ListWrapper.in("parentID", setTemp);
                listArea = baseMapper.selectList(ListWrapper);
            }
            //将pid加入分页查询条件
            wrapper.in("parentID", set);
        }
        //将关键词加入查询条件
        if (StrUtil.isNotEmpty(query.getQueryCondition())) {
            wrapper.like("name", query.getQueryCondition());
        }
        //执行查询
        Page<Area> result = baseMapper.selectPage(Page, wrapper);

        return PageDTO.create(result, AreaInfoDTO.class);
    }

    private void buildPositionTree(AreaTreeInfoDTO currentNode, List<Area> AreaList, int depth) {
        List<AreaTreeInfoDTO> AreaTreeInfoDTOList = new ArrayList<>();
        currentNode.setNodes(AreaTreeInfoDTOList);
        if (depth != 0 && currentNode.getLevel() >= depth) {
            return;
        }
        for (Area area : AreaList) {
            if (Objects.equals(area.getParentID(), currentNode.getId())) {
                AreaTreeInfoDTO childNode = new AreaTreeInfoDTO();
                BeanUtils.copyProperties(area, childNode);
                childNode.setLevel(currentNode.getLevel() + 1); // 设置子节点的深度
                childNode.setTreeName("||-"+currentNode.getName());//设置子节点的树名称
                currentNode.getNodes().add(childNode); // 将子节点添加到当前节点的子节点列表中
                buildPositionTree(childNode, AreaList,depth); // 递归构建子节点的子节点
            }
        }
    }

    @Override
    public JsonVO<Boolean> insertArea(InsertAreaDTO dto) {
        Area area = new Area();
        area.setName(dto.getName());
        area.setParentID(dto.getParentId());
        area.setSort(dto.getSort());
        area.setVisible(dto.getVisible());
        area.setIntro(dto.getIntro());

        areaMapper.insert(area);

        return JsonVO.success(true);
    }

    @Override
    public JsonVO<Boolean> deleteArea(DeleteAreaDTO dto) {
        areaMapper.deleteById(dto.getId());
        return JsonVO.success(true);
    }

    @Override
    public JsonVO<Boolean> modifyArea(ModifyAreaDTO dto) {
        Area area = new Area();

        area.setId(dto.getId());
        area.setName(dto.getName());
        area.setParentID(dto.getParentId());
        area.setSort(dto.getSort());
        area.setVisible(dto.getVisible());
        area.setIntro(dto.getIntro());

        areaMapper.updateById(area);

        return JsonVO.success(true);
    }

    // 获取地区列表
    @Override
    public List<AreaListVO> getAreaList(String keyWord) {
        if (keyWord == null){
            List<AreaListVO> areaList = areaMapper.getAreaList();
            return areaList;
        }else {
            ArrayList<AreaListVO> areaList = new ArrayList<>();
            LambdaQueryWrapper<Area> areaLambdaQueryWrapper = new LambdaQueryWrapper<Area>()
                    .like(Area::getName,keyWord);
            for (Area area : areaMapper.selectList(areaLambdaQueryWrapper)) {
                areaList.add(new AreaListVO(area.getId(),area.getName()));
            }
            return areaList;
        }
    }
}
