package com.zeroone.star.systemmanagement.service;

import com.zeroone.star.project.vo.j1.systemmanagement.RoleTreeVO;

import java.util.List;

public interface FlySysRoleTreeService {
    List<RoleTreeVO> listRoleTreeByRoleName(List<String> roleNames);
}
