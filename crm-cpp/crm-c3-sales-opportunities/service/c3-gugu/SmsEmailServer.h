#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>

#include"domain/query/c3-gugu/SmsEmailQuery.h"
/**
 * ���Ͷ��ź��ʼ��ķ����
 */
class SmsEmailService
{
public:
	// ���Ͷ���						
	bool sendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload);
	//�����ʼ�					
	bool sendEmail(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_


