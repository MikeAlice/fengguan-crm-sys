package com.zeroone.star.orgstructure.modules.position.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.common.config.OrgStructureException;
import com.zeroone.star.orgstructure.common.utils.ConvertUtil;
import com.zeroone.star.orgstructure.modules.position.entity.PositionEntity;
import com.zeroone.star.orgstructure.modules.position.mapper.PositionMapper;
import com.zeroone.star.orgstructure.modules.position.service.PositionService;
import com.zeroone.star.orgstructure.modules.user.entity.StaffEntity;
import com.zeroone.star.orgstructure.modules.user.entity.UserEntity;
import com.zeroone.star.orgstructure.modules.user.service.StaffService;
import com.zeroone.star.orgstructure.modules.user.service.UserService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.AddPositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.DeletePositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.QueryPositionDTO;
import com.zeroone.star.project.dto.j2.orgstructure.position.UpdatePositionDTO;
import com.zeroone.star.project.query.j2.orgstructure.position.GetPositionNameTreeQuery;
import com.zeroone.star.project.query.j2.orgstructure.position.PositionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.position.GetNamePositionV0;
import com.zeroone.star.project.vo.j2.orgstructure.position.PositionTreeVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.*;
import java.util.stream.Collectors;

/**
 * <p>
 * 职位表 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Service
public class PositionServiceImpl extends ServiceImpl<PositionMapper, PositionEntity> implements PositionService {
    @Resource
    private RedisTemplate<String,Object> redisTemplate;
    @Autowired
    private UserService userService;
    @Autowired
    private StaffService staffService;

    @Override
    public JsonVO<List<PositionTreeVO>> listNameTree(GetPositionNameTreeQuery getPositionNameTreeQuery) {
        List<PositionTreeVO> rootNodes = new ArrayList<>();
        //从redis中获取数据
//        List<Object> treeList = redisTemplate.opsForList().range(TreeConstant.KEY_POSITION_TREE, 0, -1);
        //如果redis有数据
//        if (ObjectUtil.isNotNull(treeList) && treeList.size() > 0) {
//            //遍历redis中的集合并增加到返回结果
//            for (Object obj : treeList) {
//                PositionTreeVO node = (PositionTreeVO) obj;
//                rootNodes.add(node);
//            }
//            return JsonVO.success(rootNodes);
//        }
        List<PositionEntity> PositionList = lambdaQuery().orderByAsc(PositionEntity::getSort).list();
        //redis中没有数据,查询数据库
        //初始化所有根节点
        for (PositionEntity Position : PositionList) {
            if (Objects.equals(Position.getParentID(), getPositionNameTreeQuery.getPid())) {
                PositionTreeVO rootNode = new PositionTreeVO();
                BeanUtils.copyProperties(Position, rootNode);
                rootNode.setLevel(1);
                rootNode.setTreeName(null);
                rootNodes.add(rootNode);
            }
        }
        //由根节点开始构建树
        for (PositionTreeVO rootNode : rootNodes) {
            buildPositionTree(rootNode, PositionList, getPositionNameTreeQuery.getDepth());
            //将数据按照队列的方式写入redis
//            redisTemplate.opsForList().rightPush(TreeConstant.KEY_POSITION_TREE, rootNode);
        }
        return JsonVO.success(rootNodes);
    }

    /**
     * 新增岗位
     * @param addPositionDTO 新增岗位DTO
     */
    @Override
//    @DeleteTreeCache(TreeEnum.Position)
    public void addPosition(AddPositionDTO addPositionDTO) {
        // 校验父级ID对应岗位是否存在 - 若父级ID非0
        validParentIDRelationPositionExist(addPositionDTO.getParentID());
        // 校验同级下是否有同名岗位
        validSameLevelSameNamePositionExist(addPositionDTO.getParentID(), addPositionDTO.getName());
        // dto转为entity
        PositionEntity positionEntity = ConvertUtil.sourceToTarget(addPositionDTO, PositionEntity.class);
        // 填充默认值
        fillAddPositionDefaultValue(positionEntity);
        // 保存到数据库
        save(positionEntity);
    }

    /**
     * 修改岗位
     * @param updatePositionDTO 修改岗位DTO
     */
    @Override
//    @DeleteTreeCache(TreeEnum.Position)
    public void updatePosition(UpdatePositionDTO updatePositionDTO) {
        // 校验岗位是否存在
        validPositionExist(updatePositionDTO.getId());
        // 校验父级ID对应岗位是否存在 - 若父级ID非0
        validParentIDRelationPositionExist(updatePositionDTO.getParentID());
        // 校验同级下是否有同名岗位，且id不为当前岗位id
        validSameLevelSameNamePositionExistAndNotCurrentPosition(updatePositionDTO.getParentID(), updatePositionDTO.getName(), updatePositionDTO.getId());
        // dto转为entity
        PositionEntity positionEntity = ConvertUtil.sourceToTarget(updatePositionDTO, PositionEntity.class);
        // 填充默认值
        fillAddPositionDefaultValue(positionEntity);
        // 更新到数据库
        updateById(positionEntity);
    }

    /**
     * 删除岗位
     * @param positionId 删除岗位DTO
     */
    @Override
//    @DeleteTreeCache(TreeEnum.Position)
    public void deletePosition(Integer positionId) {
        // 校验该岗位是否存在
        validPositionExist(positionId);
        // 校验该岗位下是否存在下级岗位
        validUnderLevelPositionExist(positionId);
        // 校验该岗位下是否有用户
        validUnderPositionUserExist(positionId);
        // 校验该岗位下是否有员工
        validUnderPositionStaffExist(positionId);
        // 删除岗位
        removeById(positionId);
    }

    private void validUnderPositionStaffExist(Integer positionId) {
        if (staffService.lambdaQuery().eq(StaffEntity::getPositionId, positionId).exists()) {
            throw new OrgStructureException("该岗位下还有员工，禁止删除");
        }
    }

    private void validUnderPositionUserExist(Integer positionId) {
        if (userService.lambdaQuery().eq(UserEntity::getPositionID, positionId).exists()) {
            throw new OrgStructureException("该岗位下还有用户，禁止删除");
        }
    }

    private void validUnderLevelPositionExist(Integer positionId) {
        if (lambdaQuery().eq(PositionEntity::getParentID, positionId).exists()) {
            throw new OrgStructureException("该岗位还有下级岗位，禁止删除");
        }
    }

    private void validSameLevelSameNamePositionExistAndNotCurrentPosition(Integer parentID, String name, Integer id) {
        if (lambdaQuery().eq(PositionEntity::getParentID, parentID == null ? 0 : parentID)
                .eq(PositionEntity::getName, name).ne(PositionEntity::getId, id).count() > 0) {
            throw new OrgStructureException("该层级下已存在同名岗位");
        }
    }

    private void validPositionExist(Integer id) {
        if (getById(id) == null) {
            throw new OrgStructureException("岗位不存在");
        }
    }

    private void fillAddPositionDefaultValue(PositionEntity positionEntity) {
        // 父级ID
        if (positionEntity.getParentID() == null) {
            positionEntity.setParentID(0);
        }
        // 排序
        if (positionEntity.getSort() == null) {
            positionEntity.setSort(0);
        }
        // 启用范围
        if (positionEntity.getVisible() == null) {
            positionEntity.setVisible(2);
        }
    }

    private void validSameLevelSameNamePositionExist(Integer parentID, String name) {
        // 同级下岗位名称为name的部门数量，不为0则存在同级同名岗位
        if (lambdaQuery().eq(PositionEntity::getParentID, parentID == null ? 0 : parentID)
                .eq(PositionEntity::getName, name).count() > 0) {
            throw new OrgStructureException("该层级下已存在同名岗位");
        }
    }

    private void validParentIDRelationPositionExist(Integer parentID) {
        if (parentID != null && parentID != 0) {
            if (getById(parentID) == null) {
                throw new OrgStructureException("父级ID对应岗位不存在");
            }
        }
    }


    /**
     * 分页查询所有数据
     * @param positionQuery 查询条件
     * @return  返回结果
     */
    @Override
    public PageDTO<QueryPositionDTO> listAll(PositionQuery positionQuery) {
        //构建分页查询对象
        Page<PositionEntity> PositionPage = new Page<>(positionQuery.getPageIndex(), positionQuery.getPageSize());
        //构建查询条件
        QueryWrapper<PositionEntity> wrapper = new QueryWrapper<>();

        //创建一个Set集合用于存储查询出来的数据的id作为分页查询条件
        Set<Integer> set = new HashSet();
        //判断pid是否为空
        if (positionQuery.getPid() != null) {
            set.add(positionQuery.getPid());
            //构建父节点查询条件
            QueryWrapper<PositionEntity> PidWrapper = new QueryWrapper<>();
            PidWrapper.eq("parentID", positionQuery.getPid());
            //查询父节点等于pid的所有数据
            List<PositionEntity> listPosition = baseMapper.selectList(PidWrapper);
            //循环获取父节点的子节点
            while (listPosition.size() != 0) {
                //创建一个临时set用于存放id
                Set<Integer> setTemp = new HashSet<>();
                //遍历列表数据
                for (PositionEntity PositionEntity : listPosition) {
                    //获取列表数据的id,将id作为父节点去查询子节点
                    Integer pid = PositionEntity.getId();
                    set.add(pid);
                    setTemp.add(pid);
                }
                //遍历setTemp集合
                //将setTemp集合中的pid加入查询集合条件
                QueryWrapper<PositionEntity> ListWrapper = new QueryWrapper<>();
                ListWrapper.in("parentID", setTemp);
                listPosition = baseMapper.selectList(ListWrapper);
            }
            //将pid加入分页查询条件
            wrapper.in("parentID", set);
        }
        //将关键词加入查询条件
        if (StrUtil.isNotEmpty(positionQuery.getKeyword())) {
            wrapper.like("name", positionQuery.getKeyword());
        }
        //执行查询
        Page<PositionEntity> result = baseMapper.selectPage(PositionPage, wrapper);
        return PageDTO.create(result, QueryPositionDTO.class);

    }

    @Override
    public JsonVO<List<GetNamePositionV0>> getnameposition(String positionName) {
        //获取所以岗位信息，并按sort升序
        List<PositionEntity> list=lambdaQuery()
                .orderByAsc(PositionEntity::getSort).list();
        // 搜索结果id集合
        Set<Integer> searchIdList;
        if (StrUtil.isEmpty(positionName)) {
            searchIdList = list.stream().map(PositionEntity::getId).collect(Collectors.toSet());
        } else {
            searchIdList = lambdaQuery().like(PositionEntity::getName, positionName).list().stream().map(PositionEntity::getId).collect(Collectors.toSet());
        }
        List<GetNamePositionV0> result=new ArrayList<>();
        //过滤第一级，递归添加至结果集
        list.stream().filter(f ->f.getParentID()==0)
                .forEach(item -> recursiveGetNameposition(item,list,result,1, searchIdList));
        return JsonVO.success(result);

    }

    private void recursiveGetNameposition(PositionEntity position, List<PositionEntity> list, List<GetNamePositionV0> positionV0s, int level, Set<Integer> searchIdList){
        if (searchIdList.contains(position.getId())) {
            //转化VO
            GetNamePositionV0 positionV0= new GetNamePositionV0();
            positionV0.setId(position.getId());
            StringBuilder prefix=new StringBuilder();
            for(int i=0;i<(level-1)*4;i++){
                prefix.append(" ");
            }
            positionV0.setName(prefix+"|--"+position.getName());
            //添加结果集
            positionV0s.add(positionV0);
        }
        //过滤下一级别
        list.stream().filter(f -> Objects.equals(f.getParentID(),position.getId()))
                .forEach(item -> recursiveGetNameposition(item,list,positionV0s,level+1, searchIdList));
    }

    private void buildPositionTree(PositionTreeVO currentNode, List< PositionEntity > PositionList, int depth) {
        List<PositionTreeVO> PositionTreeVOList = new ArrayList<>();
        currentNode.setNodes(PositionTreeVOList);
        if (depth != 0 && currentNode.getLevel() >= depth) {
            return;
        }
        for (PositionEntity Position : PositionList) {
            if (Objects.equals(Position.getParentID(), currentNode.getId())) {
                PositionTreeVO childNode = new PositionTreeVO();
                BeanUtils.copyProperties(Position, childNode);
                childNode.setLevel(currentNode.getLevel() + 1); // 设置子节点的深度
                childNode.setTreeName("||-"+currentNode.getName());//设置子节点的树名称
                currentNode.getNodes().add(childNode); // 将子节点添加到当前节点的子节点列表中
                buildPositionTree(childNode, PositionList, depth); // 递归构建子节点的子节点
            }
        }
    }
}