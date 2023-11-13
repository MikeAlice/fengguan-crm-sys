package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.login.MenuTreeVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;

import java.util.List;

public interface RoleTreeApis {
    JsonVO<List<RoleTreeVO>> getRoleTree() throws Exception;
}
