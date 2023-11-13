package com.zeroone.star.systemmanagement.service.impl;

import com.zeroone.star.systemmanagement.entity.FlySysMenu;
import com.zeroone.star.systemmanagement.mapper.FlySysMenuMapper;
import com.zeroone.star.systemmanagement.service.IFlySysMenuService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 系统菜单栏目 服务实现类
 * </p>
 *
 * @author dzcgood
 * @since 2023-10-20
 */
@Service
public class FlySysMenuServiceImpl extends ServiceImpl<FlySysMenuMapper, FlySysMenu> implements IFlySysMenuService {
    @Resource
    private FlySysMenuMapper flySysMenuMapper;

    @Override
    public List<Integer> getChildId(int id) {
        return flySysMenuMapper.getChildId(id);
    }
}
