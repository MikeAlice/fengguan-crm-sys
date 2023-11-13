package com.zeroone.star.systemmanagement.controller;

import com.zeroone.star.project.j1.systemmanagement.RoleListApis;
import com.zeroone.star.project.j1.systemmanagement.RoleTreeApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleListVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class RoleController implements RoleTreeApis, RoleListApis {
    @Override
    public JsonVO<List<RoleTreeVO>> getRoleTree() throws Exception {
        return null;
    }

    @Override
    public JsonVO<List<RoleListVO>> getRoleList() throws Exception {
        return null;
    }
}
