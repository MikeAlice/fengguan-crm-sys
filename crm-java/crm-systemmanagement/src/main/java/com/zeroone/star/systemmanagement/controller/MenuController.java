package com.zeroone.star.systemmanagement.controller;

import com.zeroone.star.project.j1.systemmanagement.SystemMenuApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuTreeVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MenuVO;
import com.zeroone.star.systemmanagement.service.MenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import javax.validation.constraints.Min;
import java.util.List;


@RestController
@RequestMapping("/menu")
@Api(tags = "菜单管理")
@Validated
public class MenuController implements SystemMenuApis {

    @Resource
    private MenuService menuService;

    @ApiOperation(value = "查询菜单列表")
    @GetMapping("/{id}")
    @Override
    public JsonVO<List<MenuVO>> getMenuList(@PathVariable Integer id) {
        return JsonVO.success(menuService.getMenuList(id));
    }

    @ApiOperation(value = "查询菜单名称树")
    @GetMapping("/tree")
    @Override
    public JsonVO<MenuTreeVO> getMenuTree() {
        return JsonVO.success(menuService.getMenuTree());
    }

}
