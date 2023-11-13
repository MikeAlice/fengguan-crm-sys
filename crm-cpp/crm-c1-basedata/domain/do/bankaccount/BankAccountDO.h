#pragma once
#ifndef _BANKACCOUNT_DO_
#define _BANKACCOUNT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class BankAccountDO
{
	// ���
	CC_SYNTHESIZE(uint64_t,bank_id,Bank_id);
	// ������������
	CC_SYNTHESIZE(string, name, Name);
	// �����˺�
	CC_SYNTHESIZE(uint64_t, card, Card);
	// ���е�ַ
	CC_SYNTHESIZE(string, address, Address);
	//������
	CC_SYNTHESIZE(string,holders,Holders);
	//����
	CC_SYNTHESIZE(uint64_t, sort, Sort);
	//�Ƿ�����
	CC_SYNTHESIZE(uint64_t, visible, Visible);//��֪��bool������ɶ


public:
	BankAccountDO() {
		bank_id = 0;
		name = "";
		card = 0;
		address = "";
		holders = "";
		sort = 0;
		visible = 0;
	}
};
class BankAccountListDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, bank_id, Bank_id);
	// ������������
	CC_SYNTHESIZE(string, name, Name);
	// �����˺�
	CC_SYNTHESIZE(uint64_t, card, Card);

public:
	BankAccountListDO() {
		bank_id = 0;
		name = "";
		card = 0;
		
	}
};

#endif // !_BANKACCOUNT_DO_