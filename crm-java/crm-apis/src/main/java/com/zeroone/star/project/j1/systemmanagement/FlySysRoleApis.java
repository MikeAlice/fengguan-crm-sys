package com.zeroone.star.project.j1.systemmanagement;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.login.MenuTreeVO;
import com.zeroone.star.project.vo.j1.systemmanagement.FlySysRoleVO;

import javax.swing.tree.TreeNode;
import java.util.List;

public interface FlySysRoleApis {
    /**
     * 获取权限数据（list）
     * @return 权限数据
     * @throws Exception 异常信息
     */
    JsonVO<List<FlySysRoleVO>> getRoleLists() throws Exception;

    /**
     * 获取权限数据（Tree）
     * @return 权限数据
     * @throws Exception 异常信息
     */
    JsonVO<List<FlySysRoleVO>> getRoleTrees() throws Exception;
}
