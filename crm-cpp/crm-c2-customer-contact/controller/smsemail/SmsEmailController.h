#pragma once
/*
* 负责人：地灵殿
*/
#ifndef SMSEMAILCONTROLLER_H__
#define SMSEMAILCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include"domain/dto/smsemail/SmsEmailDTO.h"
#include"domain/dto/smsemail/EmailDTO.h"
#include"domain/dto/smsemail/SmsDTO.h"
#include"domain/vo/smsemail/SmsEmailVO.h"
#include"domain/query/smsemail/SmsEmailQuery.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

//定义前缀
#ifndef SEC_PRFIX
#define SEC_PRFIX(_app_) "customer-contact"#_app_
#endif // !SEC_PRFIX

/**
 * SmsEmail控制器：发送短信和邮件
 */
class SmsEmailController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SmsEmailController);
public:// 3 定义接口
	//获取发送内容接口
	//发送短信接口
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, SEC_PRFIX(/send-sms), querySendSms, BODY_DTO(SmsEmailQuery::Wrapper, qdto), execSendSms(qdto, authObject->getPayload()));
	ENDPOINT_INFO(querySendSms)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("smsemail.controller.send-sms.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//发送邮件接口
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, SEC_PRFIX(/send-email), querySendEmail, BODY_DTO(SmsEmailQuery::Wrapper, qdto), execSendEmail(qdto, authObject->getPayload()));
	ENDPOINT_INFO(querySendEmail)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("smsemail.controller.send-email.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	
private:
	//发送短信
	StringJsonVO::Wrapper execSendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload);
	//发送邮件
	StringJsonVO::Wrapper execSendEmail(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload);
};

//  取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // SMSEMAILCONTROLLER_H_