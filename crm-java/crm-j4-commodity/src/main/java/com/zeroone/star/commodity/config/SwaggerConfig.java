package com.zeroone.star.commodity.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @author 骇客老薛
 * @date 2023/10/22 21:12
 * com.zeroone.star.commodity.config
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {

    @Bean
    Docket commodityApi(){
        return SwaggerCore.defaultDocketBuilder("商品管理块","com.zeroone.star.commodity.controller","commodity");

    }
}

