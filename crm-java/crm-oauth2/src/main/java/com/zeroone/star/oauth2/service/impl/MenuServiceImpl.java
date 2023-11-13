package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.FlySysMenu;
import com.zeroone.star.oauth2.mapper.FlySysMenuMapper;
import com.zeroone.star.oauth2.service.IMenuService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<FlySysMenuMapper, FlySysMenu> implements IMenuService {

    @Override
    public List<FlySysMenu> listAllLinkUrl() {
        QueryWrapper<FlySysMenu> wrapper = new QueryWrapper<>();
        wrapper.select("url");
        wrapper.isNotNull("url");
        return baseMapper.selectList(wrapper);
    }
}
