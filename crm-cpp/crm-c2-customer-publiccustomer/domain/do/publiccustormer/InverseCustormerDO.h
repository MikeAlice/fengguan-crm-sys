//2023��10��25��
//��Ƥ�����
//�����ͻ���DO
#pragma once
#ifndef _INVERSE_CUSTORMER_DO_
#define _INVERSE_CUSTORMER_DO_
#include "../DoInclude.h"

class InverseCustormerDO {
	// �ͻ�ID
	CC_SYNTHESIZE(uint64_t, custormerId, CustormerID);
	// ��ϵ��ID
	CC_SYNTHESIZE(uint64_t, linkManId, LinkManID);
public:
	InverseCustormerDO() {
		custormerId = -1;
		linkManId = -1;
	}
};

#endif // !_INVERSE_CUSTORMER_DO_
