package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMenuDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author DzcGood
 * @date 2023/10/20 - 16:26
 */
public interface FlySysMenuApis {
    /**
     * 修改系统菜单
     * @param flySysMenuDTO 要修改的内容
     * @return 修改后的系统菜单信息
     */
    JsonVO<FlySysMenuDTO> updateMenu(FlySysMenuDTO flySysMenuDTO);

    /**
     * 根据递归删除系统菜单
     * @param id 要删除的系统菜单id
     * @return 操作成功或失败
     */
    JsonVO<String> removeMenuById(int id);

    /**
     * 添加系统菜单
     * @param flySysMenuDTO 要添加的系统菜单信息
     * @return 添加结果
     */
    JsonVO<FlySysMenuDTO> addMenu(FlySysMenuDTO flySysMenuDTO);
}
