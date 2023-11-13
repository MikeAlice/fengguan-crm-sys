package com.zeroone.star.purchasemanagement.common.utils;

import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

/**
 * 获取当前登录用户ID工具类
 *
 * @author j2
 * @since 2023/10/29
 */
@Component
public class UserUtil {
    @Autowired
    private UserHolder userHolder;

    /**
     * 获取用户ID
     * @return 当前登录用户ID，或者静态值1
     */
    public Integer getUserId() {
        try {
            return userHolder.getCurrentUser().getId();
        } catch (Exception e) {
            return 1;
        }
    }
}
