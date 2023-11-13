#pragma once
#ifndef _SMSEMAIL_DAO_
#define _SMSEMAIL_DAO_
#include "BaseDAO.h"
#include"domain/do/c3-gugu/SmsMailDO.h"

/**
 * ��ѯ���ݿ����ʵ��
 */

class SmsEmailDAO : public BaseDAO
{
public:
	//��ѯ��������
	list<EmailDO> queryEmail(const int& customer_no);
	//��ѯ��ϵ�ֻ�
	list<SmsDO> queryMobile(const int& customer_no);
};
#endif // !_SMSEMAIL_DAO_

