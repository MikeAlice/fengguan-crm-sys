#ifndef _SMSEMAILAPICLIENT_H_
#define _SMSEMAILAPICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"
#include"domain/dto/c3-gugu/SmsMailDTO.h"


/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class SmsEmailApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(SmsEmailApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// �������Ͷ���
	API_CALL(API_M_GET, "/message/sms", sendSms, QUERY(oatpp::List<SmsDTO::Wrapper>, smsdto));
	// ���������ʼ�
	API_CALL(API_M_GET, "/message/mail", sendEmail, QUERY(oatpp::List<MailDTO::Wrapper>, emaildto));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

#endif // !_SMSEMAILAPICLIENT_H_