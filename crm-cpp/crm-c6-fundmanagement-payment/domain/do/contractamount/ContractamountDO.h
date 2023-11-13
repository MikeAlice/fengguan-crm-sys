#pragma once
#ifndef _CONTRACTAMOUNT_DO_
#define _CONTRACTAMOUNT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ContractamountDO
{
	// �ܽ��
	CC_SYNTHESIZE(uint64_t, total_money, Total_money);
	// ȥ����
	CC_SYNTHESIZE(uint64_t, zero_money, Zero_money);
	// �Ѹ����
	CC_SYNTHESIZE(uint64_t, paid_money, Paid_money);
	// �Ѹ���Ʊ���
	CC_SYNTHESIZE(uint64_t, invoice_money, Invoice_money);
public:
	ContractamountDO() {
		total_money = 0;
		zero_money = 0;
		paid_money = 0;
		invoice_money = 0;
	}
};

#endif // !_CONTRACTAMOUNT_DO_