package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.FlySysRole;
import com.zeroone.star.oauth2.mapper.FlySysRoleMapper;
import com.zeroone.star.oauth2.mp.MethodRoleMP;
import com.zeroone.star.oauth2.service.IRoleService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class RoleServiceImpl extends ServiceImpl<FlySysRoleMapper, FlySysRole> implements IRoleService {

    @Override
    public List<FlySysRole> listRoleByUserId(int userId) {
        return baseMapper.selectByUserId(userId);
    }

    @Override
    public List<FlySysRole> listRoleByMenuPath(String path) {
        return baseMapper.selectByMenuPath(path);
    }

    @Override
    public List<MethodRoleMP> getMethodRoleList() {
        return baseMapper.getMethodRoleList();
    }
}
