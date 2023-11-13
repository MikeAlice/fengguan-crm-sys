package com.zeroone.star.orgstructure.common.annotation;

import com.zeroone.star.orgstructure.common.redis.enums.TreeEnum;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * 用来做是否要删除树缓存的标准
 * @author: Larry
 * @Date: 2023 /10 /22 / 18:14
 * @Description:
 */
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
public @interface DeleteTreeCache {
   TreeEnum  value();

}
