package com.zeroone.star.commodity.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 初始化自定义组件
 */

@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.fastdfs",
        "com.zeroone.star.project.components.easyexcel",
        "com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.jwt"}
       )
public class ComponentsInit {
}
