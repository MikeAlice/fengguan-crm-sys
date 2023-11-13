package com.zeroone.star.project.j2.orgstructure.user;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.*;

import com.zeroone.star.project.query.j2.orgstructure.user.GetUserByDeptIdOrNameQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserByDeptIdOrNameVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserNameListVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.UserExportVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

/**
 * 用户接口API定义
 *
 * @author j2
 * @version 1.0.0
 */
public interface UserApis {
    /**
     * 新增用户
     * @param addUserDTO 用户请求体参数
     * @return 统一响应模型
     */
    JsonVO<Void> addUser(AddUserDTO addUserDTO);

    /**
     * 修改用户状态
     * @param modifyUserStatusDTO 用户请求体参数id
     * @return 统一响应模型
     */
    JsonVO<Void>  modifyUserStatus(ModifyUserStatusDTO modifyUserStatusDTO);

    /**
     * 根据部门Id或者姓名查询用户(分页+条件)
     * @param getUserByDeptIdOrNameQuery  封装的用户请求体参数
     * @return  封装的统一响应模型
     */
    JsonVO<PageDTO<GetUserByDeptIdOrNameVO>> queryAllByDeptIdOrName(GetUserByDeptIdOrNameQuery getUserByDeptIdOrNameQuery);

    /**
     * 修改用户
     * @param updateUserDTO 用户请求体参数
     * @return 统一响应模型
     */
    JsonVO<Void> updateUser(UpdateUserDTO updateUserDTO);

    /**
     * 删除用户
     * @param userId 用户ID
     * @return 统一响应模型
     */
    JsonVO<Void> deleteUser(Integer userId);

    /*
  系统用户名列表数据
  @param userNameListDTO 用户请求体参数(用户id)
  @return 统一响应模型
 */
    JsonVO<List<GetUserNameListVO>> getUserNameList(GetUserNameListDTO userNameListDTO);

    /*
    用户的导入
    @param path 文件路径参数
    @return 统一响应模型
     */
    JsonVO<Void> ImportUser(MultipartFile file);

    /*
    用户的导出
    @param exportUserDTOs 用户响应体参数
     */
    JsonVO<UserExportVO> exportUser(List<Integer> ids);
}
