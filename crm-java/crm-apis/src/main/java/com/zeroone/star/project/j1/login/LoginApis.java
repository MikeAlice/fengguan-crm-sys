package com.zeroone.star.project.j1.login;

import com.zeroone.star.project.dto.j1.login.LoginDTO;
import com.zeroone.star.project.dto.j1.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.login.LoginVO;
import com.zeroone.star.project.vo.j1.login.MenuTreeVO;

import java.util.List;

/**
 * <p>
 * 描述：用户登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface LoginApis {

    /**
     * 获取菜单数据
     * @return 菜单数据
     * @throws Exception 异常信息
     */
    JsonVO<List<MenuTreeVO>> getMenus() throws Exception;
}
