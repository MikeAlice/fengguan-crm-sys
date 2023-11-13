package com.zeroone.star.systemmanagement.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysAddMethodDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMethodDTO;
import com.zeroone.star.project.j1.systemmanagement.FlySysMethodApis;
import com.zeroone.star.project.query.j1.systemmanagement.GetMethodListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.MethodListVO;
import com.zeroone.star.systemmanagement.service.IFlySysMethodService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 系统方法 前端控制器
 * </p>
 *
 * @author 点点
 * @since 2023-11-01
 */
@RestController
@Api(tags = "权限管理")
@RequestMapping("systemmanagement")
public class FlySysMethodController implements FlySysMethodApis {

    @Resource
    private IFlySysMethodService flySysMethodService;

    /**
     *添加权限
     * @param flySysMethodDTO 权限传输对象
     * @return 操作结果
     */
    @Override
    @ApiOperation("添加权限")
    @PostMapping("add-method")
    public JsonVO<String> addMethod(@RequestBody FlySysAddMethodDTO flySysMethodDTO) {
        boolean isSuccess = flySysMethodService.saveMethod(flySysMethodDTO);
        if (isSuccess)return JsonVO.success("添加成功");
        else return JsonVO.fail("添加失败");
    }

    @Override
    @ApiOperation("修改权限")
    @PutMapping("modify-method")
    public JsonVO<String> modifyMethod(@RequestBody FlySysMethodDTO flySysMethodDTO) {
        boolean isSuccess = flySysMethodService.updateMethod(flySysMethodDTO);
        if (isSuccess)return JsonVO.success("修改成功");
        else return JsonVO.fail("修改失败");
    }
    
    @GetMapping("get-method-list")
    @ApiOperation(value = "获取权限列表")
    @Override
    public JsonVO<PageDTO<MethodListVO>> getMethodList(@RequestBody GetMethodListQuery getMethodListQuery) {
        PageDTO<MethodListVO> result = flySysMethodService.getMethodList(getMethodListQuery);
        return JsonVO.success(result);
    }

    @ApiOperation(value = "删除权限")
    @DeleteMapping("/delete-method")
    @Override
    public JsonVO<Boolean> DeleteMethod(FlySysMethodDTO flySysMethodDTO){
        boolean flag= flySysMethodService.removeById(flySysMethodDTO.getId());
        return JsonVO.success(flag);
    }
}

