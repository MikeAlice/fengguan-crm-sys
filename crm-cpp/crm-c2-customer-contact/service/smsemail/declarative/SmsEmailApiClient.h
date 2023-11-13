#ifndef _SMSEMAILAPICLIENT_H_
#define _SMSEMAILAPICLIENT_H_

// 1 导入必须头文件
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 书写示例ApiClient来演示定义声明式服务
 */
class SmsEmailApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(SmsEmailApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	// 批量发送短信
	API_CALL(API_M_POST, "/message/smss", sendSmss, BODY_DTO(oatpp::List<SmsDTO::Wrapper>, smsdto));
	// 批量发送邮件
	API_CALL(API_M_POST, "/message/mails", sendEmail, BODY_DTO(oatpp::List<EmailDTO::Wrapper>, emaildto));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 取消ApiClient控制器使用宏---结束
};

#endif // !_SMSEMAILAPICLIENT_H_