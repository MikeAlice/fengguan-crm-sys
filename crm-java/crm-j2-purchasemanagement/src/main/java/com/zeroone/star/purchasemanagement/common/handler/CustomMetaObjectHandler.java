package com.zeroone.star.purchasemanagement.common.handler;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.purchasemanagement.common.utils.UserUtil;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.Date;

/**
 * @author j2
 * @since 2023/10/29
 */
@Component
public class CustomMetaObjectHandler implements MetaObjectHandler {
    @Autowired
    private UserUtil userUtil;

    @Override
    public void insertFill(MetaObject metaObject) {
        // 创建时间
        setFieldValByName("createTime", new Date(), metaObject);
        // 创建用户ID
        setFieldValByName("createUserId", userUtil.getUserId(), metaObject);
    }

    @Override
    public void updateFill(MetaObject metaObject) {

    }
}
