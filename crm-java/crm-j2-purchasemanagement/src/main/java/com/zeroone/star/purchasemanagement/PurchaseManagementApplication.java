package com.zeroone.star.purchasemanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;

/**
 * 采购管理模块启动类
 *
 * @author j2
 * @since 2023/10/29
 */
@EnableFeignClients
@EnableDiscoveryClient
@SpringBootApplication
public class PurchaseManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(PurchaseManagementApplication.class, args);
    }
}
