//狗皮电耗子
//2023年10月23日
//基础客户DO删除客户和投入公海公用
#pragma once
#ifndef _BASE_CUSTORMER_DO_
#define _BASE_CUSTORMER_DO_
#include "../DoInclude.h"

class BaseCustormerDO {
	// 客户ID
	CC_SYNTHESIZE(uint64_t, custormerId, CustormerID);
public:
	BaseCustormerDO() {
		custormerId = 1;
	}
};

#endif // !_BASE_CUSTORMER_DO_
