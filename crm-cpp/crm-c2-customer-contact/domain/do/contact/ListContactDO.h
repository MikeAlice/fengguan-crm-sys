#pragma once
/*
* �����ˣ��Ͼ�
*/

#ifndef _LISTCONTACT_DO_
#define _LISTCONTACT_DO_
#include "../DoInclude.h"

/**
 * ��ȡ��ϵ���б�ʵ����
 */
class ListContactDO
{
	// ��ϵ�˱��
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkman_Id);
	// �ͻ�����
	CC_SYNTHESIZE(string, customer_name, Customer_Name);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(uint64_t, gender, Gender);
	// ְλ
	CC_SYNTHESIZE(string, postion, Postion);
	// ����
	CC_SYNTHESIZE(string, tel, Tel);
	// �ֻ�
	CC_SYNTHESIZE(string, mobile, Mobile);
	// qq
	CC_SYNTHESIZE(string, qicq, Qicq);

public:
	ListContactDO() {
		linkman_id = 0;
		customer_name = "";
		name = "";
		gender = 1;
		postion = "";
		tel = "";
		mobile = "";
		qicq = "";
	}
};
#endif // !_LISTCONTACT_DO_