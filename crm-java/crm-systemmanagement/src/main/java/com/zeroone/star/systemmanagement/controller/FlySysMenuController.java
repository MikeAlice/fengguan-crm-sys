package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMenuDTO;
import com.zeroone.star.project.j1.systemmanagement.FlySysMenuApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanagement.entity.FlySysMenu;
import com.zeroone.star.systemmanagement.service.IFlySysMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.models.auth.In;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 系统菜单栏目 前端控制器
 * </p>
 *
 * @author dzcgood
 * @since 2023-10-20
 */
@RestController
@Api(tags = "fly-sys-menu")
@RequestMapping("/systemmanagement/fly-sys-menu")
public class FlySysMenuController implements FlySysMenuApis {
    @Resource
    private IFlySysMenuService flySysMenuService;

    private FlySysMenu buildFlySysMenu(FlySysMenuDTO flySysMenuDTO) {
        return FlySysMenu.builder()
                .id(flySysMenuDTO.getId())
                .name(flySysMenuDTO.getName())
                .nameEn(flySysMenuDTO.getNameEn())
                .url(flySysMenuDTO.getUrl())
                .parentID(flySysMenuDTO.getParentID())
                .sort(flySysMenuDTO.getSort())
                .visible(flySysMenuDTO.getVisible())
                .build();
    }

    private FlySysMenuDTO buildFlySysMenuDTO(FlySysMenu flySysMenu) {
        return FlySysMenuDTO.builder()
                .id(flySysMenu.getId())
                .name(flySysMenu.getName())
                .nameEn(flySysMenu.getNameEn())
                .url(flySysMenu.getUrl())
                .parentID(flySysMenu.getParentID())
                .sort(flySysMenu.getSort())
                .visible(flySysMenu.getVisible())
                .build();
    }

    @Override
    @ApiOperation("修改菜单")
    @PutMapping("update")
    public JsonVO<FlySysMenuDTO> updateMenu(@RequestBody FlySysMenuDTO flySysMenuDTO) {
        if (flySysMenuDTO.getId() == null) {
            return JsonVO.create(null, 9999, "菜单id为空");
        }
        FlySysMenu flySysMenu = buildFlySysMenu(flySysMenuDTO);
        if (flySysMenuService.updateById(flySysMenu)) {
            return JsonVO.success(flySysMenuDTO);
        }
        return JsonVO.create(null, 9999, "更新菜单失败");
    }

    @Override
    @ApiOperation("删除菜单和子菜单")
    @DeleteMapping("delete/{id}")
    public JsonVO<String> removeMenuById(@PathVariable int id) {
        if (flySysMenuService.getById(id) == null) {
            return JsonVO.create(null, 9999, "id为" + id + "的菜单不存在");
        }
        List<Integer> ids = flySysMenuService.getChildId(id);
        if (flySysMenuService.removeByIds(ids)) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.create(null, 9999, "删除失败");
    }

    @Override
    @ApiOperation("添加系统菜单")
    @PostMapping("add")
    public JsonVO<FlySysMenuDTO> addMenu(@RequestBody FlySysMenuDTO flySysMenuDTO) {
        FlySysMenu flySysMenu = buildFlySysMenu(flySysMenuDTO);
        Integer id = flySysMenuDTO.getId();
        if (id != null && flySysMenuService.getById(id) != null) {
            return JsonVO.create(null, 9999, "id为" + id + "的菜单已存在");
        }
        if (flySysMenuService.save(flySysMenu)) {
            FlySysMenu menu = flySysMenuService.getById(id);
            return JsonVO.success(buildFlySysMenuDTO(menu));
        }
        return JsonVO.create(null, 9999, "添加菜单失败");
    }
}

