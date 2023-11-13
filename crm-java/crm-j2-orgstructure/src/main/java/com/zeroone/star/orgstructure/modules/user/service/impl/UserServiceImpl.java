package com.zeroone.star.orgstructure.modules.user.service.impl;

import cn.hutool.core.collection.CollectionUtil;
import cn.hutool.core.util.StrUtil;
import cn.hutool.crypto.digest.MD5;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgstructure.common.config.OrgStructureException;
import com.zeroone.star.orgstructure.common.utils.ConvertUtil;
import com.zeroone.star.orgstructure.modules.dept.entity.DeptEntity;
import com.zeroone.star.orgstructure.modules.dept.service.DeptService;
import com.zeroone.star.orgstructure.modules.position.entity.PositionEntity;
import com.zeroone.star.orgstructure.modules.position.service.PositionService;
import com.zeroone.star.orgstructure.modules.role.entity.RoleEntity;
import com.zeroone.star.orgstructure.modules.role.service.RoleService;
import com.zeroone.star.orgstructure.modules.user.entity.UserEntity;
import com.zeroone.star.orgstructure.modules.user.excel.UserExcel;
import com.zeroone.star.orgstructure.modules.user.mapper.GetUserByDeptIdOrNameVOMapper;
import com.zeroone.star.orgstructure.modules.user.mapper.UserMapper;
import com.zeroone.star.orgstructure.modules.user.service.UserService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.AddUserDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.GetUserNameListDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.ModifyUserStatusDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.UpdateUserDTO;
import com.zeroone.star.project.query.j2.orgstructure.user.GetUserByDeptIdOrNameQuery;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserByDeptIdOrNameVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserNameListVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.UserExportVO;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.stream.Collectors;


/**
 * <p>
 * 系统用户表 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, UserEntity> implements UserService {
    @Autowired
    private DeptService deptService;
    @Autowired
    private PositionService positionService;
    @Autowired
    private RoleService roleService;
    @Autowired
    private EasyExcelComponent easyExcelComponent;
    @Autowired
    private FastDfsClientComponent fastDfsClientComponent;
    @Autowired
    private GetUserByDeptIdOrNameVOMapper getUserByDeptIdOrNameVOMapper;

    @Value("${fastdfs.nginx-servers}")
    private String fastdfsServerUrl;

    /**
     * 新增用户
     * @param addUserDTO 用户请求体参数
     */
    @Override
    public void addUser(AddUserDTO addUserDTO) {
        // 校验对应部门是否存在
        validDeptExist(addUserDTO.getDeptID());
        // 校验对应岗位是否存在
        validPositionExist(addUserDTO.getPositionID());
        // 校验对应角色是否存在
        validRoleExist(addUserDTO.getRoleID());
        // 校验对应账号是否已存在
        validAccountAlreadyExist(addUserDTO.getAccount());
        // 请求对象转化为实体类
        UserEntity user = ConvertUtil.sourceToTarget(addUserDTO, UserEntity.class);
        // 密码加密并设置
        user.setPassword(MD5.create().digestHex16(addUserDTO.getPassword()));
        // 填充默认值
        fillDefaultValueInAddUser(user);
        // 保存用户信息到数据库
        save(user);
    }

    /**
     * 修改用户
     * @param updateUserDTO 用户请求体参数
     */
    @Override
    public void updateUser(UpdateUserDTO updateUserDTO) {
        // 校验对应用户是否存在
        validUserExist(updateUserDTO.getId());
        // 校验对应部门是否存在
        validDeptExist(updateUserDTO.getDeptID());
        // 校验对应岗位是否存在
        validPositionExist(updateUserDTO.getPositionID());
        // 校验对应角色是否存在
        validRoleExist(updateUserDTO.getRoleID());
        // 校验账号是否已存在 - 且非当前用户
        validAccountAlreadyExistAndNotCurrentUser(updateUserDTO.getId(), updateUserDTO.getAccount());
        // 请求对象转化为实体类
        UserEntity user = ConvertUtil.sourceToTarget(updateUserDTO, UserEntity.class);
        // 设置密码 - 若为空则不进行修改，也即设置为null - 不为空则加密并设置
        user.setPassword(StrUtil.isEmpty(updateUserDTO.getPassword()) ? null : MD5.create().digestHex16(updateUserDTO.getPassword()));
        // 更新用户信息到数据库
        updateById(user);
    }

    /**
     * 删除用户
     * @param userId 用户ID
     */
    @Override
    public void deleteUser(Integer userId) {
        // 删除用户，返回值false则抛出异常
        if (!removeById(userId)) {
            throw new OrgStructureException("用户不存在");
        }
    }

    /**
     * 获取列表(分页+条件)
     * @param query
     * @return 查询结果
     */
    @Override
    public PageDTO<GetUserByDeptIdOrNameVO> listAllByDeptIdOrName(GetUserByDeptIdOrNameQuery query) {
        Page<GetUserByDeptIdOrNameQuery> page = Page.of(query.getPageIndex(), query.getPageSize());
        Page<GetUserByDeptIdOrNameVO> idOrNameVO = getUserByDeptIdOrNameVOMapper.selectAll(page, query);
        //将page对象转化为list对象
        List<GetUserByDeptIdOrNameVO> records = idOrNameVO.getRecords();
        //将list对象进行遍历，再把数据库中gender的值1，2解析为对应的男，女
        for (GetUserByDeptIdOrNameVO record : records) {
            if(record.getGender().equals("1")){
                record.setShowGender("男");
            }else if(record.getGender().equals("2")){
                record.setShowGender("女");
            }
        }
        //将list对象封装到page对象里面
        idOrNameVO.setRecords(records);
        return PageDTO.create(idOrNameVO);
    }

    /**
     * 修改用户状态status
     * @param modifyUserStatusDTO
     */
    @Override
    public void modifyUserStatus(ModifyUserStatusDTO modifyUserStatusDTO) {
        //查询id对应用户是否存在
        Integer id = modifyUserStatusDTO.getId();
        validUserExist(id);
        //获取查询的用户实体
        UserEntity user = getById(id);
        //若当前状态为0则变为1，若当前状态为1则变为0
        if (user.getStatus() == 0){
            user.setStatus(1);
        }else {
            user.setStatus(0);
        }
        updateById(user);
    }

    private void validUserExist(Integer userId) {
        if (getById(userId) == null) {
            throw new OrgStructureException("该用户不存在");
        }
    }

    private void validAccountAlreadyExistAndNotCurrentUser(Integer userId, String account) {
        UserEntity user = lambdaQuery().eq(UserEntity::getAccount, account).one();
        if (user != null && !Objects.equals(user.getId(), userId)) {
            throw new OrgStructureException("账号已存在");
        }
    }

    private void fillDefaultValueInAddUser(UserEntity user) {
        // 地址
        user.setAddress("");
        // 邮政编码
        user.setZipcode("");
        // 电话
        user.setTel("");
        // adt - 默认当前时间
        user.setAdt(new Date());
        // 身份账号
        user.setIdentity("");
        // 状态 - 默认为0正常状态
        user.setStatus(0);
    }

    private void validAccountAlreadyExist(String account) {
        if (lambdaQuery().eq(UserEntity::getAccount, account).one() != null) {
            throw new OrgStructureException("账号已存在");
        }
    }

    private void validRoleExist(Integer roleID) {
        if (roleService.getById(roleID) == null) {
            throw new OrgStructureException("角色不存在");
        }
    }

    private void validPositionExist(Integer positionID) {
        if (positionService.getById(positionID) == null) {
            throw new OrgStructureException("岗位不存在");
        }
    }

    private void validDeptExist(Integer deptID) {
        if (deptService.getById(deptID) == null) {
            throw new OrgStructureException("部门不存在");
        }
    }

    @Override
    public List<GetUserNameListVO> listAll(GetUserNameListDTO userNameListDTO) {
        LambdaQueryWrapper<UserEntity> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.like(userNameListDTO.getName()!=null,UserEntity::getName,userNameListDTO.getName());
        List<UserEntity> userEntities = baseMapper.selectList(queryWrapper);
        return  ConvertUtil.sourceToTarget(userEntities, GetUserNameListVO.class);
    }


    /**
     * 导出用户
     * @param userIdList 用户ID集合
     * @return 导出用户VO
     */
    @Override
    public UserExportVO exportUser(List<Integer> userIdList) {
        // 校验用户id集合是否为空
        if (CollectionUtil.isEmpty(userIdList)) {
            throw new OrgStructureException("用户ID集合不能为空");
        }
        // mapper查询用户excel集合
        List<UserExcel> userExcelList = baseMapper.getUserExcelListByIds(userIdList);
        // 遍历 - 修改性别
        userExcelList.forEach(item -> item.setGender("1".equals(item.getGender()) ? "男" : "女"));
        // 导出用户excel集合到文件中，上传至fastdfs，并返回文件地址
        String url = exportUserExcelToFastDFS(userExcelList);
        // 构建vo并返回
        UserExportVO userExportVO = new UserExportVO();
        userExportVO.setUrl(url);
        return userExportVO;
    }

    /**
     * 导入用户
     * @param file 用户excel表格文件
     */
    @Override
    @SneakyThrows
    @Transactional(rollbackFor = Exception.class)
    public void ImportUser(MultipartFile file) {
        // 读取文件到用户excel实体类集合
        List<UserExcel> userExcelList = readExcelFileToUserExcelList(file);
        // 初始值校验、非空校验
        initValidUserExcel(userExcelList);
        // 部门: 名称-id分组
        Map<String, Integer> deptMap = deptService.lambdaQuery().in(DeptEntity::getName, userExcelList.stream().map(UserExcel::getDept).collect(Collectors.toList())).list()
                .stream().collect(Collectors.toMap(DeptEntity::getName, DeptEntity::getId));
        // 岗位：名称-id分组
        Map<String, Integer> positionMap = positionService.lambdaQuery().in(PositionEntity::getName, userExcelList.stream().map(UserExcel::getPosition).collect(Collectors.toList())).list()
                .stream().collect(Collectors.toMap(PositionEntity::getName, PositionEntity::getId));
        // 角色：名称-id分组
        Map<String, Integer> roleMap = roleService.lambdaQuery().in(RoleEntity::getName, userExcelList.stream().map(UserExcel::getRole).collect(Collectors.toList())).list()
                .stream().collect(Collectors.toMap(RoleEntity::getName, RoleEntity::getId));
        // 校验excel类集合合法性
        validUserExcel(userExcelList, deptMap, positionMap, roleMap);
        // 遍历excel类集合，映射为用户entity实体类集合
        List<UserEntity> userList = userExcelList.stream().map(userExcel -> {
            UserEntity user = ConvertUtil.sourceToTarget(userExcel, UserEntity.class);
            // 性别
            user.setGender("男".equals(userExcel.getGender()) ? "1" : "2");
            // 部门
            user.setDeptID(deptMap.get(userExcel.getDept()));
            // 岗位
            user.setPositionID(positionMap.get(userExcel.getPosition()));
            // 角色
            user.setRoleID(String.valueOf(roleMap.get(userExcel.getRole())));
            // 密码默认为123456
            user.setPassword(MD5.create().digestHex16("123456"));
            // dat
            user.setAdt(new Date());
            return user;
        }).collect(Collectors.toList());
        // 批量保存
        saveBatch(userList);
    }

    private void validUserExcel(List<UserExcel> userExcelList, Map<String, Integer> deptMap, Map<String, Integer> positionMap, Map<String, Integer> roleMap) {
        // 账号是否已存在
        UserEntity user = lambdaQuery().in(UserEntity::getAccount, userExcelList.stream().map(UserExcel::getAccount).collect(Collectors.toList())).last("limit 1").one();
        if (user != null) {
            throw new RuntimeException(String.format("%s账号已存在", user.getAccount()));
        }
        for (UserExcel userExcel : userExcelList) {
            // 部门是否存在
            if (deptMap.get(userExcel.getDept()) == null) {
                throw new RuntimeException(String.format("%s部门不存在", userExcel.getDept()));
            }
            // 岗位是否存在
            if (positionMap.get(userExcel.getPosition()) == null) {
                throw new RuntimeException(String.format("%s岗位不存在", userExcel.getPosition()));
            }
            // 角色是否存在
            if (roleMap.get(userExcel.getRole()) == null) {
                throw new RuntimeException(String.format("%s角色不存在", userExcel.getRole()));
            }
        }
    }

    private static List<UserExcel> readExcelFileToUserExcelList(MultipartFile file) throws IOException {
        ExcelReadListener<UserExcel> userExcelExcelReadListener = new ExcelReadListener<>();
        EasyExcel.read(file.getInputStream(), UserExcel.class, userExcelExcelReadListener).sheet().doRead();
        return userExcelExcelReadListener.getDataList();
    }

    private void initValidUserExcel(List<UserExcel> userExcelList) {
        for (UserExcel userExcel : userExcelList) {
            if (StrUtil.isEmpty(userExcel.getAccount())) {
                throw new RuntimeException("账号不能为空");
            }
            if (StrUtil.isEmpty(userExcel.getName())) {
                throw new RuntimeException("姓名不能为空");
            }
            if (StrUtil.isEmpty(userExcel.getGender())) {
                // 默认为男
                userExcel.setGender("男");
            }
            if (!"男".equals(userExcel.getGender()) && !"女".equals(userExcel.getGender())) {
                throw new RuntimeException("性别仅限为男 | 女");
            }
            if (StrUtil.isEmpty(userExcel.getMobile())) {
                throw new RuntimeException("手机号不能为空");
            }
            if (StrUtil.isEmpty(userExcel.getDept())) {
                throw new RuntimeException("部门不能为空");
            }
            if (StrUtil.isEmpty(userExcel.getPosition())) {
                throw new RuntimeException("岗位不能为空");
            }
            if (StrUtil.isEmpty(userExcel.getRole())) {
                throw new RuntimeException("角色不能为空");
            }
        }
    }

    @SneakyThrows
    private String exportUserExcelToFastDFS(List<UserExcel> userExcelList) {
        // 导出用户excel集合到输出流中
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        easyExcelComponent.export("用户表格", out, UserExcel.class, userExcelList);
        // 上传文件输出流到fastdfs
        FastDfsFileInfo fastDfsFileInfo = fastDfsClientComponent.uploadFile(out.toByteArray(), "xlsx");
        out.close();
        // 获取文件地址并返回
        return fastDfsClientComponent.fetchUrl(fastDfsFileInfo, fastdfsServerUrl, true);
    }
}
