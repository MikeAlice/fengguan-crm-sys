package com.zeroone.star.commodity.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 导入String序列化的RedisTemplate
 * @author 张二发
 */
@Configuration
@ComponentScan("com.zeroone.star.project.config.redis")
public class RedisInit {
}