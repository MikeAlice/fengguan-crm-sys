//��Ƥ�����
//2023��10��23��
//�����ͻ�DOɾ���ͻ���Ͷ�빫������
#pragma once
#ifndef _BASE_CUSTORMER_DO_
#define _BASE_CUSTORMER_DO_
#include "../DoInclude.h"

class BaseCustormerDO {
	// �ͻ�ID
	CC_SYNTHESIZE(uint64_t, custormerId, CustormerID);
public:
	BaseCustormerDO() {
		custormerId = 1;
	}
};

#endif // !_BASE_CUSTORMER_DO_
