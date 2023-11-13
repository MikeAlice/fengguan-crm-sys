package com.zeroone.star.orgstructure.feign;

import com.zeroone.star.orgstructure.feign.fallback.OAuth2ClientFallback;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

/**
 * OAuth2认证模块feign客户端接口
 *
 * @author 汐
 * @since 2023/11/9
 */
@FeignClient(value = "${sn.auth}", fallbackFactory = OAuth2ClientFallback.class)
public interface OAuth2Client {
    @GetMapping("/refresh-method-role-map")
    JsonVO<Void> refreshMethodRoleMap();
}
