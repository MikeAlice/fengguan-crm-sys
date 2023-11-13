package com.zeroone.star.systemmanagement.service;

import com.zeroone.star.project.vo.j1.systemmanagement.RoleListVO;
import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;

import java.util.List;

public interface FlySysRoleListService {
    List<RoleListVO> listRoleListByRoleName(List<String> roleNames);
}
