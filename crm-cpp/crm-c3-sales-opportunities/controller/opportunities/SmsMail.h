#pragma once
#ifndef _SEAN_MALL_H
#define _SEND_MALL_H

#include"domain/vo/BaseJsonVO.h"
#include"domain/query/PageQuery.h"
#include"ApiHelper.h"

#include"domain/dto/c3-gugu/SmsMailDTO.h"
#include"domain/query/c3-gugu/SmsEmailQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController)

class MallController :public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(MallController);

public://定义接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("opportunities.controller.send_mail"), send_mail, BooleanJsonVO::Wrapper)
		API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-opportunities/salesContract/Mail/", send_mail, BODY_DTO(SmsEmailQuery::Wrapper, dto), execSendMail(dto, authObject->getPayload()));

private:

	StringJsonVO::Wrapper execSendMail(const SmsEmailQuery::Wrapper, const PayloadDTO& payload);
};



class SmsController :public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(SmsController);

public://定义接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("opportunities.controller.send_sms"), send_sms, BooleanJsonVO::Wrapper)
		API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-opportunities/salesContract/Sms/", send_sms, BODY_DTO(SmsEmailQuery::Wrapper, dto), execSendSms(dto, authObject->getPayload()));

private:
	StringJsonVO::Wrapper execSendSms(const SmsEmailQuery::Wrapper, const PayloadDTO& payload);
};



#include OATPP_CODEGEN_END(ApiController)


#include OATPP_CODEGEN_END(ApiController)

#endif // !_SEAN_MALL_H

