#pragma once
#ifndef _DICTTPYE_DO_
#define _DICTTPYE_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����-�ֵ����
 */
class DictTypeDO 
{
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �ֵ��������
	CC_SYNTHESIZE(string, name, Name);

public:
	DictTypeDO() {
		id = 0;
		name = "";
	}
};

#endif // !_DICTTPYE_DO_