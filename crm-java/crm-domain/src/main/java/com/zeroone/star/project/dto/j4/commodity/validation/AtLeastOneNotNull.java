package com.zeroone.star.project.dto.j4.commodity.validation;

import javax.validation.Constraint;
import javax.validation.Payload;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Target({ElementType.TYPE})
@Retention(RetentionPolicy.RUNTIME)
// 指定约束校验器
@Constraint(validatedBy = AtLeastOneNotNullValidator.class)
public @interface AtLeastOneNotNull {
    String message() default "非ID字段至少有一个不为null";
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}
