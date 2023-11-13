package com.zeroone.star.orgstructure.modules.dept.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.common.config.OrgStructureException;
import com.zeroone.star.orgstructure.modules.dept.entity.DeptEntity;
import com.zeroone.star.orgstructure.modules.dept.mapper.DeptMapper;
import com.zeroone.star.orgstructure.modules.dept.service.DeptService;
import com.zeroone.star.orgstructure.modules.user.entity.StaffEntity;
import com.zeroone.star.orgstructure.modules.user.entity.UserEntity;
import com.zeroone.star.orgstructure.modules.user.service.StaffService;
import com.zeroone.star.orgstructure.modules.user.service.UserService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.AddDeptDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.DeptDTO;
import com.zeroone.star.project.dto.j2.orgstructure.dept.QueryDeptDTO;
import com.zeroone.star.project.query.j2.orgstructure.dept.DeptQuery;
import com.zeroone.star.project.query.j2.orgstructure.dept.GetDeptNameTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.dept.DeptTreeVO;
import com.zeroone.star.project.vo.j2.orgstructure.dept.GetNameDeptV0;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.*;
import java.util.stream.Collectors;

/**
 * <p>
 * 部门表 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Service
public class DeptServiceImpl extends ServiceImpl<DeptMapper, DeptEntity> implements DeptService {
    @Resource
    private RedisTemplate<String,Object> redisTemplate;
    @Autowired
    private UserService userService;
    @Autowired
    private StaffService staffService;

    //redis树形结构的key
    private static final String keyByTree="dept_tree";

    @Override
//    @DeleteTreeCache(TreeEnum.Dept)
    public JsonVO<Long> addDept(AddDeptDTO dto) {
        if (getOne(new QueryWrapper<DeptEntity>()
                .eq("name", dto.getName())
                .eq("parentID", dto.getParentID())) != null) {
            return JsonVO.create(0L, 403, "添加失败，同级目录下已有同名部门存在");
        }
        DeptEntity entity = DeptEntity.builder()
                .name(dto.getName())
                .parentID(dto.getParentID())
                .sort(dto.getSort())
                .visible(dto.getVisible())
                .tel(dto.getTel())
                .fax(dto.getFax())
                .intro(dto.getIntro())
                .build();
        return save(entity) ? JsonVO.success(1L) : JsonVO.fail(0L);
    }

    @Override
//    @DeleteTreeCache(TreeEnum.Dept)
    public JsonVO<Long> updateDept(DeptDTO dto) {
        // 校验是否存在同级、同名部门且非当前部门
        if (lambdaQuery()
                .eq(DeptEntity::getParentID, dto.getParentID())
                .eq(DeptEntity::getName, dto.getName())
                .ne(DeptEntity::getId, dto.getId()).exists()) {
            throw new OrgStructureException("同级部门下存在同名部门");
        }
        DeptEntity entity = DeptEntity.builder()
                .id(dto.getId())
                .name(dto.getName())
                .parentID(dto.getParentID())
                .sort(dto.getSort())
                .visible(dto.getVisible())
                .tel(dto.getTel())
                .fax(dto.getFax())
                .intro(dto.getIntro())
                .build();
        return updateById(entity) ? JsonVO.success(1L) : JsonVO.fail(0L);
    }

    @Override
//    @DeleteTreeCache(TreeEnum.Dept)
    public JsonVO<Long> deleteDept(Integer id) {
        // 校验是否有用户关联该部门
        if (userService.lambdaQuery().eq(UserEntity::getDeptID, id).exists()) {
            throw new OrgStructureException("存在用户关联该岗位，禁止删除");
        }
        // 校验是否有员工关联该部门
        if (staffService.lambdaQuery().eq(StaffEntity::getDeptId, id).exists()) {
            throw new OrgStructureException("存在员工关联该岗位，禁止删除");
        }
        if (getOne(new QueryWrapper<DeptEntity>()
                .eq("parentID", id)
                .ne("id", id)
                .last("LIMIT 1")) == null) {
            return removeById(id) ? JsonVO.success(1L) : JsonVO.fail(0L);
        } else {
            return JsonVO.create(0L, 403, "删除失败，该部门仍有子部门存在");
        }
    }

    @Override
    public JsonVO<List<GetNameDeptV0>> getnamedept(String deptName) {
        //获取所以部门信息，并按sort升序
        List<DeptEntity> list=lambdaQuery()
                .orderByAsc(DeptEntity::getSort).list();
        // 搜索结果id
        Set<Integer> searchIdSet;
        if (StrUtil.isEmpty(deptName)) {
            searchIdSet = list.stream().map(DeptEntity::getId).collect(Collectors.toSet());
        } else {
            searchIdSet = lambdaQuery().like(DeptEntity::getName, deptName).list().stream().map(DeptEntity::getId).collect(Collectors.toSet());
        }
       List<GetNameDeptV0> result=new ArrayList<>();
        //过滤第一级，递归添加至结果集
       list.stream().filter(f ->f.getParentID()==0)
               .forEach(item -> recursiveGetNameDept(item,list,result,1, searchIdSet));
   return JsonVO.success(result);

    }
    private void recursiveGetNameDept(DeptEntity dept, List<DeptEntity> list, List<GetNameDeptV0> deptV0List, int level, Set<Integer> searchIdSet){
        if (searchIdSet.contains(dept.getId())) {
            //转化VO
            GetNameDeptV0 deptV0= new GetNameDeptV0();
            deptV0.setId(dept.getId());
            StringBuilder prefix=new StringBuilder();
            for(int i=0;i<(level-1)*4;i++){
                prefix.append(" ");
            }
            deptV0.setName(prefix+"|--"+dept.getName());
            //添加结果集
            deptV0List.add(deptV0);
        }
        //过滤下一级别
        list.stream().filter(f -> Objects.equals(f.getParentID(),dept.getId()))
                .forEach(item -> recursiveGetNameDept(item,list,deptV0List,level+1, searchIdSet));
    }



    @Override
    public JsonVO<List<DeptTreeVO>> getNameTree(GetDeptNameTreeQuery getDeptNameTreeQuery) {
        List<DeptTreeVO> rootNodes=new ArrayList<>();
        //从redis中获取数据
//        List<Object> treeList = redisTemplate.opsForList().range(TreeConstant.KEY_DEPT_TREE, 0, -1);
        //如果redis有数据
//        if(ObjectUtil.isNotNull(treeList)&&treeList.size() > 0)
//        {
//            //遍历redis中的集合并增加到返回结果
//            for (Object obj : treeList) {
//                DeptTreeVO node = (DeptTreeVO) obj;
//                rootNodes.add(node);
//            }
//            return JsonVO.success(rootNodes);
//        }
        List<DeptEntity> deptList= lambdaQuery().orderByAsc(DeptEntity::getSort).list();
        //redis中没有数据,查询数据库
        //初始化所有根节点
        for (DeptEntity dept: deptList) {
             if(Objects.equals(dept.getParentID(), getDeptNameTreeQuery.getPid()))
             {
                 DeptTreeVO rootNode = new DeptTreeVO();
                 BeanUtils.copyProperties(dept, rootNode);
                 rootNode.setLevel(1);
                 rootNode.setTreeName(null);
                 rootNodes.add(rootNode);
             }
        }
        //由根节点开始构建树
       for (DeptTreeVO rootNode: rootNodes) {
           buildDeptTree(rootNode,deptList, getDeptNameTreeQuery.getDepth());
           //将数据按照队列的方式写入redis
//           redisTemplate.opsForList().rightPush(TreeConstant.KEY_DEPT_TREE,rootNode);
       }
        return JsonVO.success(rootNodes);
    }

     private void buildDeptTree(DeptTreeVO currentNode, List<DeptEntity> deptList, Integer depth) {
        List<DeptTreeVO> deptTreeVOList = new ArrayList<>();
        currentNode.setNodes(deptTreeVOList);
        if (depth != 0 && currentNode.getLevel() >= depth) {
            return;
        }
        for (DeptEntity dept : deptList) {
            if (Objects.equals(dept.getParentID(), currentNode.getId())) {
                DeptTreeVO childNode = new DeptTreeVO();
                BeanUtils.copyProperties(dept, childNode);
                childNode.setLevel(currentNode.getLevel() + 1); // 设置子节点的深度
                childNode.setTreeName("||-"+currentNode.getName());//设置子节点的树名称
                currentNode.getNodes().add(childNode); // 将子节点添加到当前节点的子节点列表中
                buildDeptTree(childNode, deptList, depth); // 递归构建子节点的子节点
            }
        }
    }

    /**
     * 分页查询所有数据
     *
     * @param deptQuery 查询条件
     * @return 返回结果
     */
    @Override
    public PageDTO<QueryDeptDTO> listAll(DeptQuery deptQuery) {
        //构建分页查询对象
        Page<DeptEntity> deptPage=new Page<>(deptQuery.getPageIndex(),deptQuery.getPageSize());
        //构建查询条件
        QueryWrapper<DeptEntity> wrapper=new QueryWrapper<>();

        //创建一个Set集合用于存储查询出来的数据的id作为分页查询条件
        Set<Integer> set=new HashSet();
        //判断pid是否为空
        if(deptQuery.getPid()!=null){
            set.add(deptQuery.getPid());
            //构建父节点查询条件
            QueryWrapper<DeptEntity> PidWrapper=new QueryWrapper<>();
            PidWrapper.eq("parentID",deptQuery.getPid());
            //查询父节点等于pid的所有数据
            List<DeptEntity> listDept = baseMapper.selectList(PidWrapper);

            //循环获取父节点的子节点
            while (listDept.size()!=0){
                //创建一个临时set用于存放id
                Set<Integer> setTemp=new HashSet<>();
                //遍历列表数据
                for (DeptEntity deptEntity : listDept) {
                    //获取列表数据的id,将id作为父节点去查询子节点
                    Integer pid = deptEntity.getId();
                    set.add(pid);
                    setTemp.add(pid);
                }
                //遍历setTemp集合
                //将setTemp集合中的pid加入查询集合条件
                QueryWrapper<DeptEntity> ListWrapper=new QueryWrapper<>();
                ListWrapper.in("parentID",setTemp);
                listDept = baseMapper.selectList(ListWrapper);
            }
            //将pid加入分页查询条件
            wrapper.in("parentID",set);
        }
        //将关键词加入查询条件
        if (StrUtil.isNotEmpty(deptQuery.getKeywords())) {
            wrapper.like("name",deptQuery.getKeywords());
        }
        //执行查询
        Page<DeptEntity> result = baseMapper.selectPage(deptPage, wrapper);
        return PageDTO.create(result, QueryDeptDTO.class);
    }

}
