package com.zeroone.star.orgstructure;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;

/**
 * 组织结构服务启动类
 *
 * @author j2
 * @version 1.0.0
 */
@EnableFeignClients
@EnableDiscoveryClient
@SpringBootApplication
public class OrgStructureApplication {
    public static void main(String[] args) {
        SpringApplication.run(OrgStructureApplication.class, args);
    }
}
