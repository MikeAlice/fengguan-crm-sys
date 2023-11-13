package com.zeroone.star.oauth2.controller;

import com.zeroone.star.oauth2.service.impl.ResourceServiceImpl;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @author 汐
 * @since 2023/11/9
 */
@RestController
public class RefreshController {
    @Resource
    private ResourceServiceImpl resourceServiceImpl;

    /**
     * 刷新redis中方法value-角色集合映射hash
     */
    @GetMapping("refresh-method-role-map")
    public JsonVO<Void> refreshMethodRoleMap() {
        resourceServiceImpl.init();
        return JsonVO.success(null);
    }
}
