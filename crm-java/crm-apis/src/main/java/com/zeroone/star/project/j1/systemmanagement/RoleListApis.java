package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleListVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;

import java.util.List;

public interface RoleListApis {
    JsonVO<List<RoleListVO>> getRoleList() throws Exception;
}
