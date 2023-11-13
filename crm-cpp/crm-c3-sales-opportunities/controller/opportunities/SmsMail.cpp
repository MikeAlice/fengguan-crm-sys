#include "stdafx.h"
#include "SmsMail.h"
#include"service/c3-gugu/SmsEmailServer.h"
#include"../ApiDeclarativeServicesHelper.h"

StringJsonVO::Wrapper MallController::execSendMail(const SmsEmailQuery::Wrapper qdto, const PayloadDTO& payload)
{
	//����һ��server
	SmsEmailService service;
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//�ǿ�У��
	if (!qdto->chance_id)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	//ִ�����ݲ���
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
	//����һ��server
	SmsEmailService service;
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//�ǿ�У��
	if (!qdto->chance_id)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	//ִ�����ݲ���
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