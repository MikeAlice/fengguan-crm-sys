package com.zeroone.star.orgstructure.modules.user.controller;


import com.zeroone.star.orgstructure.modules.user.service.UserService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.AddUserDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.GetUserNameListDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.ModifyUserStatusDTO;
import com.zeroone.star.project.dto.j2.orgstructure.user.UpdateUserDTO;
import com.zeroone.star.project.j2.orgstructure.user.UserApis;
import com.zeroone.star.project.query.j2.orgstructure.user.GetUserByDeptIdOrNameQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserByDeptIdOrNameVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserNameListVO;
import com.zeroone.star.project.vo.j2.orgstructure.user.UserExportVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 * 系统用户表 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@RestController
@RequestMapping("/user/user")
@Api(tags = "用户接口")
public class UserController implements UserApis {
    @Autowired
    private UserService userService;

    @Resource
    EasyExcelComponent easyExcel;

    @PostMapping("add-user")
    @ApiOperation(value = "新增用户")
    @Override
    public JsonVO<Void> addUser(@Valid @RequestBody AddUserDTO addUserDTO) {
        userService.addUser(addUserDTO);
        return JsonVO.success(null);
    }

    @PutMapping("update-user")
    @ApiOperation(value = "修改用户")
    @Override
    public JsonVO<Void> updateUser(@Valid @RequestBody UpdateUserDTO updateUserDTO) {
        userService.updateUser(updateUserDTO);
        return JsonVO.success(null);
    }

    @DeleteMapping("delete-user")
    @ApiOperation(value = "删除用户")
    @Override
    public JsonVO<Void> deleteUser(@ApiParam(value = "用户ID", required = true) @RequestParam Integer userId) {
        userService.deleteUser(userId);
        return JsonVO.success(null);
    }


    @PutMapping("modify-user-status")
    @ApiOperation(value = "冻结/解冻用户")
    @Override
    public JsonVO<Void> modifyUserStatus(@Valid @RequestBody ModifyUserStatusDTO modifyUserStatusDTO) {
        userService.modifyUserStatus(modifyUserStatusDTO);
        return JsonVO.success(null);
    }

    @GetMapping("query-all-by-deptid-or-name")
    @ApiOperation(value = "获取用户列表 (分页+条件)")
    @Override
    public JsonVO<PageDTO<GetUserByDeptIdOrNameVO>> queryAllByDeptIdOrName(GetUserByDeptIdOrNameQuery query) {
        return JsonVO.success(userService.listAllByDeptIdOrName(query));
    }

    @GetMapping("get-userName-list")
    @ApiOperation(value = "系统用户名列表数据 (用于输入表单下拉列表)")
    @Override
    public JsonVO<List<GetUserNameListVO>> getUserNameList(GetUserNameListDTO userNameListDTO) {
        return JsonVO.success(userService.listAll(userNameListDTO));
    }

    @GetMapping("export-user")
    @ApiOperation(value = "导出用户")
    @Override
    public JsonVO<UserExportVO> exportUser(@ApiParam(value = "用户ID集合") @RequestParam List<Integer> userIdList) {
        UserExportVO userExportVO = userService.exportUser(userIdList);
        return JsonVO.success(userExportVO);
    }

    @PostMapping("import-user")
    @ApiOperation(value = "导入用户")
    @Override
    public JsonVO<Void> ImportUser(@ApiParam(value = "用户excel表格文件") @RequestParam MultipartFile file) {
        userService.ImportUser(file);
        return JsonVO.success(null);
    }
}

