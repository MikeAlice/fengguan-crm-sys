package com.zeroone.star.orgstructure.feign.fallback;

import com.zeroone.star.orgstructure.feign.OAuth2Client;
import com.zeroone.star.project.vo.JsonVO;
import feign.hystrix.FallbackFactory;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

/**
 * OAuth2认证模块feign客户端接口熔断降级回调
 *
 * @author 汐
 * @since 2023/11/9
 */
@Slf4j
@Component
public class OAuth2ClientFallback implements FallbackFactory<OAuth2Client> {
    @Override
    public OAuth2Client create(Throwable cause) {
        cause.printStackTrace();
        return new OAuth2Client() {
            @Override
            public JsonVO<Void> refreshMethodRoleMap() {
                return JsonVO.fail(null);
            }
        };
    }
}
