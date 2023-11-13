package com.zeroone.star.commodity.Exception;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;

import javax.validation.ConstraintViolation;
import javax.validation.ConstraintViolationException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

//@RestControllerAdvice(basePackages = "com.zeroone.star.commodity.controller")
public class ValidationExceptionControllerAdvice {
    @ExceptionHandler({MethodArgumentNotValidException.class})
    public JsonVO<Map<String, String>> methodArgumentNotValidException(MethodArgumentNotValidException e){
        BindingResult bindingResult = e.getBindingResult();
        if(bindingResult.hasErrors()){
            List<FieldError> fieldErrors = bindingResult.getFieldErrors();
            Map<String,String> map=new HashMap<>();
            fieldErrors.forEach(fieldError -> {
                String defaultMessage = fieldError.getDefaultMessage();
                String field = fieldError.getField();
                map.put(field,defaultMessage);
            });
            return JsonVO.fail(map);
        }
        return null;
    }


    @ExceptionHandler({ ConstraintViolationException.class})
    public JsonVO<String> methodArgumentNotValidException(ConstraintViolationException e){
        Set<ConstraintViolation<?>> violations = e.getConstraintViolations();
        Stream<String> stringStream = violations.stream().map(ConstraintViolation::getMessage);
        String result = stringStream.collect(Collectors.joining(";"));
        return JsonVO.fail(result);
    }
}

