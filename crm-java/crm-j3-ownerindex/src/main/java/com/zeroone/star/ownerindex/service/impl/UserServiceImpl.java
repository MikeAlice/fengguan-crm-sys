package com.zeroone.star.ownerindex.service.impl;

import com.zeroone.star.ownerindex.entity.User;
import com.zeroone.star.ownerindex.mapper.UserMapper;
import com.zeroone.star.ownerindex.service.UserService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyOwnerInfoDTO;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyPwdDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Description: UserService实现类
 * @Author: your name
 * @Date: 2023/10/24 17:27
 */
@Service
public class UserServiceImpl implements UserService {

    @Autowired
    private UserMapper userMapper;

    @Autowired
    private UserHolder userHolder;

    @Override
    public Boolean modifyPassword(ModifyPwdDTO dto) throws Exception {
        UserDTO currentUser = userHolder.getCurrentUser();
        if(userMapper.SelectPwdById(currentUser.getId()).equals(dto.getOldPassword()) != true){
            return false;
        }
        return userMapper.modifyPwdById(currentUser.getId(), dto.getNewPassword());
    }

    @Override
    public Boolean modifyOwnerInfo(ModifyOwnerInfoDTO dto) throws Exception {
        UserDTO currentUser = userHolder.getCurrentUser();
        User user = new User(dto);
        user.setId(currentUser.getId());
        int i = userMapper.updateById(user);
        if (i == 0){
            return false;
        }
        return true;
    }
}
