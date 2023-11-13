#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>

#include"domain/query/c3-gugu/SmsEmailQuery.h"
/**
 * 发送短信和邮件的服务层
 */
class SmsEmailService
{
public:
	// 发送短信						
	bool sendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload);
	//发送邮件					
	bool sendEmail(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_


