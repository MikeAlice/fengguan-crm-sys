package com.zeroone.star.orgstructure.modules.role.service.impl;

import cn.hutool.core.collection.CollectionUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.common.config.OrgStructureException;
import com.zeroone.star.orgstructure.feign.OAuth2Client;
import com.zeroone.star.orgstructure.modules.role.entity.MethodEntity;
import com.zeroone.star.orgstructure.modules.role.entity.RoleEntity;
import com.zeroone.star.orgstructure.modules.role.entity.RoleMenuEntity;
import com.zeroone.star.orgstructure.modules.role.entity.RoleMethodEntity;
import com.zeroone.star.orgstructure.modules.role.mapper.RoleMapper;
import com.zeroone.star.orgstructure.modules.role.service.MethodService;
import com.zeroone.star.orgstructure.modules.role.service.RoleMenuService;
import com.zeroone.star.orgstructure.modules.role.service.RoleMethodService;
import com.zeroone.star.orgstructure.modules.role.service.RoleService;
import com.zeroone.star.orgstructure.modules.user.entity.UserEntity;
import com.zeroone.star.orgstructure.modules.user.service.UserService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.AddRoleDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.QueryRoleDTO;
import com.zeroone.star.project.dto.j2.orgstructure.role.UpdateRoleDTO;
import com.zeroone.star.project.query.j2.orgstructure.role.GetRoleTreeNameQuery;
import com.zeroone.star.project.query.j2.orgstructure.role.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.GetNameRoleVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.RoleTreeVO;
import org.apache.commons.lang.StringUtils;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.*;
import java.util.stream.Collectors;

/**
 * <p>
 * 权限列表 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */

@Service
public class RoleServiceImpl extends ServiceImpl<RoleMapper, RoleEntity> implements RoleService {
    @Autowired
    private UserService userService;
    @Autowired
    private RoleMenuService roleMenuService;
    @Resource
    private RedisTemplate<String,Object> redisTemplate;
    @Resource
    private RoleMethodService roleMethodService;
    @Resource
    private MethodService methodService;
    @Resource
    private OAuth2Client oAuth2Client;

    @Override
    public JsonVO<List<RoleTreeVO>> listNameTree(GetRoleTreeNameQuery getRoleTreeNameQuery) {
        List<RoleTreeVO> rootNodes = new ArrayList<>();
        //从redis中获取数据
//        List<Object> treeList = redisTemplate.opsForList().range(TreeConstant.KEY_ROLE_TREE, 0, -1);
        //如果redis有数据
//        if (ObjectUtil.isNotNull(treeList) && treeList.size() > 0) {
//            //遍历redis中的集合并增加到返回结果
//            for (Object obj : treeList) {
//                RoleTreeVO node = (RoleTreeVO) obj;
//                rootNodes.add(node);
//            }
//            return JsonVO.success(rootNodes);
//        }
        List<RoleEntity> RoleList = lambdaQuery().orderByAsc(RoleEntity::getSort).list();
        //redis中没有数据,查询数据库
        //初始化所有根节点
        for (RoleEntity Role : RoleList) {
            if (Objects.equals(Role.getParentID(), getRoleTreeNameQuery.getPid())) {
                RoleTreeVO rootNode = new RoleTreeVO();
                BeanUtils.copyProperties(Role, rootNode);
                rootNode.setLevel(1);
                rootNode.setTreeName(null);
                rootNodes.add(rootNode);
            }
        }
        //由根节点开始构建树
        for (RoleTreeVO rootNode : rootNodes) {
            buildRoleTree(rootNode, RoleList, getRoleTreeNameQuery.getDepth());
            //将数据按照队列的方式写入redis
//            redisTemplate.opsForList().rightPush(TreeConstant.KEY_ROLE_TREE, rootNode);
        }
        return JsonVO.success(rootNodes);
    }

    /**
     * 分页查询所有数据
     *
     * @param roleQuery 查询条件
     * @return 查询结果
     */
    @Override
    public PageDTO<QueryRoleDTO> listAll(RoleQuery roleQuery) {
        //构建分页查询对象
        Page<RoleEntity> RolePage = new Page<>(roleQuery.getPageIndex(), roleQuery.getPageSize());
        //构建查询条件
        QueryWrapper<RoleEntity> wrapper = new QueryWrapper<>();
        //创建一个Set集合用于存储查询出来的数据的id作为分页查询条件
        Set<Integer> set = new HashSet();
        //判断pid是否为空
        if (roleQuery.getPid() != null) {
            set.add(roleQuery.getPid());
            //构建父节点查询条件
            QueryWrapper<RoleEntity> PidWrapper = new QueryWrapper<>();
            PidWrapper.eq("parentID", roleQuery.getPid());
            //查询父节点等于pid的所有数据
            List<RoleEntity> listRole = baseMapper.selectList(PidWrapper);

            //循环获取父节点的子节点
            while (listRole.size() != 0) {
                //创建一个临时set用于存放id
                Set<Integer> setTemp = new HashSet<>();
                //遍历列表数据
                for (RoleEntity RoleEntity : listRole) {
                    //获取列表数据的id,将id作为父节点去查询子节点
                    Integer pid = RoleEntity.getId();
                    set.add(pid);
                    setTemp.add(pid);
                }
                //遍历setTemp集合
                //将setTemp集合中的pid加入查询集合条件
                QueryWrapper<RoleEntity> ListWrapper = new QueryWrapper<>();
                ListWrapper.in("parentID", setTemp);
                listRole = baseMapper.selectList(ListWrapper);
            }
            //将pid加入分页查询条件
            wrapper.in("parentID", set);
        }
        //将关键词加入查询条件
        if (StrUtil.isNotEmpty(roleQuery.getKeyword())) {
            wrapper.like("name", roleQuery.getKeyword());
        }
        //执行查询
        Page<RoleEntity> result = baseMapper.selectPage(RolePage, wrapper);
        return PageDTO.create(result, QueryRoleDTO.class);

    }

    @Override
    public  JsonVO<List<GetNameRoleVO>> getnamerole(){
        //获取所以角色信息，并按sort升序
        List<RoleEntity> list=lambdaQuery()
                .orderByAsc(RoleEntity::getSort).list();
        List<GetNameRoleVO> result=new ArrayList<>();
        //过滤第一级，递归添加至结果集
        list.stream().filter(f ->f.getParentID()==0)
                .forEach(item -> recursiveGetNameRole(item,list,result,1));
        return JsonVO.success(result);

    }

    @Override
    @Transactional(rollbackFor = Exception.class)
//    @DeleteTreeCache(TreeEnum.Role)
    public JsonVO<Long> addRole(AddRoleDTO dto) {
        if(StringUtils.isBlank(dto.getName())){
            return JsonVO.create(0L, 403, "角色名称为空");
        }
        if (getOne(new QueryWrapper<RoleEntity>()
                .eq("name", dto.getName())
                .eq("parentID", dto.getParentID())) != null) {
            return JsonVO.create(0L, 403, "添加失败，同级目录下已有同名角色存在");
        }
        RoleEntity role = new RoleEntity();
        BeanUtils.copyProperties(dto,role);
        boolean result = save(role);
        // 为角色设置默认权限 - menuID为0的系统方法
        Integer roleId = role.getId();
        List<MethodEntity> methodList = methodService.lambdaQuery().select(MethodEntity::getId).eq(MethodEntity::getMenuID, 0).list();
        if (CollectionUtil.isNotEmpty(methodList)) {
            List<RoleMethodEntity> roleMethodList = methodList.stream().map(item -> {
                RoleMethodEntity roleMethodEntity = new RoleMethodEntity();
                roleMethodEntity.setRoleId(roleId);
                roleMethodEntity.setMethodId(item.getId());
                return roleMethodEntity;
            }).collect(Collectors.toList());
            roleMethodService.saveBatch(roleMethodList);
            // 远程调用oauth2模块刷新权限方法-角色列表缓存
            oAuth2Client.refreshMethodRoleMap();
        }
        return result ? JsonVO.success(1L) : JsonVO.fail(0L);
    }

    @Override
//    @DeleteTreeCache(TreeEnum.Role)
    public JsonVO<Long> updateRole(UpdateRoleDTO dto) {
        // 检查角色ID是否有效
        if (dto.getId() == null || dto.getId() <= 0) {
            return JsonVO.fail(0L);
        }
        // 检查角色名称是否为空
        if (StringUtils.isBlank(dto.getName())) {
            return JsonVO.fail(0L);
        }
        //检查是否有同级同名存在
        RoleEntity one = getOne(new QueryWrapper<RoleEntity>()
                .eq("name", dto.getName())
                .eq("parentID", dto.getParentID()));
        if (one != null&& one.getId()!=dto.getId()) {
            return JsonVO.create(0L, 403, "添加失败，同级目录下已有同名角色存在");
        }
        RoleEntity role = new RoleEntity();
        BeanUtils.copyProperties(dto,role);
        return updateById(role) ? JsonVO.success(1L) : JsonVO.fail(0L);

    }

    @Override
//    @DeleteTreeCache(TreeEnum.Role)
    @Transactional(rollbackFor = Exception.class)
    public JsonVO<Long> removeRole(Integer id) {
        // 检查角色ID是否有效
        if (id== null || id <= 0) {
            return JsonVO.fail(0L);
        }
        //检查是否存在
        RoleEntity one = getOne(new QueryWrapper<RoleEntity>().eq("id", id));
        if(one == null){
            return JsonVO.fail(0L);
        }
        // 校验是否有用户关联该角色
        if (userService.lambdaQuery().eq(UserEntity::getRoleID, id).exists()) {
            throw new OrgStructureException("存在用户关联该角色，禁止删除");
        }
        // 删除对应角色-菜单关联项
        roleMenuService.lambdaUpdate().eq(RoleMenuEntity::getRoleId, id).remove();
        return removeById(id) ? JsonVO.success(1L) : JsonVO.fail(0L);
    }

    private void recursiveGetNameRole(RoleEntity role, List<RoleEntity > list, List<GetNameRoleVO> deptV0List, int level){
        //转化VO
        GetNameRoleVO roleV0= new GetNameRoleVO();
        roleV0.setId(role.getId());
        StringBuilder prefix=new StringBuilder();
        for(int i=0;i<(level-1)*4;i++){
            prefix.append(" ");
        }
        roleV0.setName(prefix+"|--"+role.getName());
        //添加结果集
        deptV0List.add(roleV0);
        //过滤下一级别
        list.stream().filter(f -> Objects.equals(f.getParentID(),role.getId()))
                .forEach(item -> recursiveGetNameRole(item,list,deptV0List,level+1));
    }

    private void buildRoleTree(RoleTreeVO currentNode, List<RoleEntity> RoleList, int depth) {
        List<RoleTreeVO> RoleTreeVOList = new ArrayList<>();
        currentNode.setNodes(RoleTreeVOList);
        if (depth != 0 && currentNode.getLevel() >= depth) {
            return;
        }
        for (RoleEntity Role : RoleList) {
            if (Objects.equals(Role.getParentID(), currentNode.getId())) {
                RoleTreeVO childNode = new RoleTreeVO();
                BeanUtils.copyProperties(Role, childNode);
                childNode.setLevel(currentNode.getLevel() + 1); // 设置子节点的深度
                childNode.setTreeName("||-"+currentNode.getName());//设置子节点的树名称
                currentNode.getNodes().add(childNode); // 将子节点添加到当前节点的子节点列表中
                buildRoleTree(childNode, RoleList, depth); // 递归构建子节点的子节点
            }
        }
    }
}

