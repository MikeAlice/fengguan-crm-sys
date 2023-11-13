package com.zeroone.star.orgstructure.common.aop;

import com.zeroone.star.orgstructure.common.annotation.DeleteTreeCache;
import com.zeroone.star.orgstructure.common.redis.constants.TreeConstant;
import com.zeroone.star.orgstructure.common.redis.enums.TreeEnum;
import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.aspectj.lang.reflect.MethodSignature;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.lang.reflect.Method;
import java.time.LocalDateTime;
import java.util.Objects;

/**
 * @author: Larry
 * @Date: 2023 /10 /22 / 18:31
 * @Description:
 */
@Aspect
@Component
@Slf4j
public class TreeAOP {
    @Resource
    private RedisTemplate<String,Object> redisTemplate;
    /**
     * 用来在方法删除树的缓存
     * 切入点
     */
    @Pointcut("execution(* com.zeroone.star.orgstructure.modules..*(..))&& @annotation(com.zeroone.star.orgstructure.common.annotation.DeleteTreeCache)")
    public void TreeEnumPointCut(){}
    @Before("TreeEnumPointCut()")
    public void TreeEnum(JoinPoint joinPoint){
        log.info("Delete Tree Cache Start"+ LocalDateTime.now());
        // 获取当前方法的Method对象
        Method currentMethod = ((MethodSignature) joinPoint.getSignature()).getMethod();

        // 获取当前方法的DeleteTreeCache注解
        DeleteTreeCache annotation = currentMethod.getAnnotation(DeleteTreeCache.class);

        // 获取注解的值
        TreeEnum value = annotation.value();
        if (Objects.isNull(value)) {
            return;
        }
        if (value.equals(TreeEnum.Dept))
        {
            redisTemplate.delete(TreeConstant.KEY_DEPT_TREE);
        }
        if (value.equals(TreeEnum.Position))
        {
            redisTemplate.delete(TreeConstant.KEY_POSITION_TREE);
        }
        if (value.equals(TreeEnum.Role))
        {
            redisTemplate.delete(TreeConstant.KEY_ROLE_TREE);
        }
        log.info("Delete Tree Cache Complete"+ LocalDateTime.now());
    }

}
