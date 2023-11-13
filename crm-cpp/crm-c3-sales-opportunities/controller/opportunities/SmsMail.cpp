#include "stdafx.h"
#include "SmsMail.h"
#include"service/c3-gugu/SmsEmailServer.h"
#include"../ApiDeclarativeServicesHelper.h"

StringJsonVO::Wrapper MallController::execSendMail(const SmsEmailQuery::Wrapper qdto, const PayloadDTO& payload)
{
	//定义一个server
	SmsEmailService service;
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//非空校验
	if (!qdto->chance_id)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	//执行数据查找
	if (service.sendEmail(qdto, payload))
	{
		jvo->success(ZH_WORDS_GETTER("opportunities.field.smsemail.success"));
	}
	else {
		jvo->fail(ZH_WORDS_GETTER("opportunities.field.smsemail.fail"));

	}
	return jvo;
}

StringJsonVO::Wrapper SmsController::execSendSms(const SmsEmailQuery::Wrapper qdto, const PayloadDTO& payload)
{
	//定义一个server
	SmsEmailService service;
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//非空校验
	if (!qdto->chance_id)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	//执行数据查找
	if (service.sendSms(qdto, payload))
	{
		jvo->success(ZH_WORDS_GETTER("opportunities.field.smsemail.success"));
	}
	else {
		jvo->fail(ZH_WORDS_GETTER("opportunities.field.smsemail.fail"));
		return jvo;
	}

	return jvo;
}