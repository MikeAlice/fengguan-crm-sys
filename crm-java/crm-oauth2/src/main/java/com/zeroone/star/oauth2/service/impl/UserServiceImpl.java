package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.FlySysUser;
import com.zeroone.star.oauth2.mapper.FlySysUserMapper;
import com.zeroone.star.oauth2.service.IUserService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class UserServiceImpl extends ServiceImpl<FlySysUserMapper, FlySysUser> implements IUserService {

}
