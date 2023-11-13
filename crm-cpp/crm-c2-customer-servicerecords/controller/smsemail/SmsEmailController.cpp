#include "stdafx.h"
#include "SmsEmailController.h"
#include"service/smsemail/SmsEmailServer.h"


StringJsonVO::Wrapper SmsEmailController::execSendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
	//定义一个server
	SmsEmailService service;
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
		//非空校验
		if ( !qdto->linkman_id)
		{
			jvo->init("-1", RS_PARAMS_INVALID);
			return jvo;
		}
		//执行数据查找
		if (service.sendSms(qdto, payload))
		{
			jvo->success(ZH_WORDS_GETTER("smsemail.smsmessage.success"));
		}
		else {
			jvo->fail(ZH_WORDS_GETTER("smsemail.smsmessage.fail"));
			return jvo;
		}

	return jvo;
}

StringJsonVO::Wrapper SmsEmailController::execSendEmail(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
	//定义一个server
	SmsEmailService service;
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
		//非空校验
		if (!qdto->linkman_id)
		{
			jvo->init("-1", RS_PARAMS_INVALID);
			return jvo;
		}
		//执行数据查找
		if (service.sendEmail(qdto, payload))
		{
			jvo->success(ZH_WORDS_GETTER("smsemail.emailmessage.success"));
		}
		else {
			jvo->fail(ZH_WORDS_GETTER("smsemail.emailmessage.fail"));
			return jvo;
		}

	return jvo;
}
