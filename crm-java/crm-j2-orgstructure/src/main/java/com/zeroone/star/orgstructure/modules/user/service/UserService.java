package com.zeroone.star.orgstructure.modules.user.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgstructure.modules.user.entity.UserEntity;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.AddUserDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.GetUserNameListDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.ModifyUserStatusDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.UpdateUserDTO;
import com.zeroone.star.project.query.j2.orgstructure.user.GetUserByDeptIdOrNameQuery;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserByDeptIdOrNameVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserNameListVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.UserExportVO;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 系统用户表 服务类
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
public interface UserService extends IService<UserEntity> {

    /**
     * 新增用户
     * @param addUserDTO 用户请求体参数
     */
    void addUser(AddUserDTO addUserDTO);

    /**
     * 修改用户
     * @param updateUserDTO 用户请求体参数
     */
    void updateUser(UpdateUserDTO updateUserDTO);

    /**
     * 删除用户
     * @param userId 用户ID
     */
    void deleteUser(Integer userId);

    /**
     * 分页查询符合条件数据
     * @param getUserByDeptIdOrNameQuery
     * @return
     */

    PageDTO<GetUserByDeptIdOrNameVO> listAllByDeptIdOrName(GetUserByDeptIdOrNameQuery getUserByDeptIdOrNameQuery);

    /**
     * 修改用户状态status
     * @param modifyUserStatusDTO
     */
    void modifyUserStatus(ModifyUserStatusDTO modifyUserStatusDTO);

    /**
     * 查询所有用户名
     * @param getUserNameListDTO
     * @return
     */
    List<GetUserNameListVO> listAll(GetUserNameListDTO getUserNameListDTO);


    /**
     * 导出用户
     * @param userIdList 用户ID集合
     * @return 导出用户VO
     */
    UserExportVO exportUser(List<Integer> userIdList);

    /**
     * 导入用户
     * @param file 用户excel表格文件
     */
    void ImportUser(MultipartFile file);
}
