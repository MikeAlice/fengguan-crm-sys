package com.zeroone.star.project.dto.j4.commodity.validation;

import org.springframework.beans.BeanWrapperImpl;

import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;
import java.beans.PropertyDescriptor;

public class AtLeastOneNotNullValidator implements ConstraintValidator<AtLeastOneNotNull, Object> {
    @Override
    public void initialize(AtLeastOneNotNull constraintAnnotation) {
    }

    @Override
    public boolean isValid(Object value, ConstraintValidatorContext context) {
        if (value == null) {
            return false;
        }
        // 通过反射来统计value中非null字段个数
        BeanWrapperImpl beanWrapper = new BeanWrapperImpl(value);
        int notNullCount = 0;
        for (PropertyDescriptor propertyDescriptor : beanWrapper.getPropertyDescriptors()) {
            String propertyName = propertyDescriptor.getName();
            if (propertyName.equals("class")){
                continue;
            }
            Object propertyValue = beanWrapper.getPropertyValue(propertyName);
            if (propertyValue != null) {
                notNullCount++;
                if (notNullCount >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
}
