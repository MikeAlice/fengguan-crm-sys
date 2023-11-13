//2023年10月25日
//狗皮电耗子
//公海客户的DO
#pragma once
#ifndef _INVERSE_CUSTORMER_DO_
#define _INVERSE_CUSTORMER_DO_
#include "../DoInclude.h"

class InverseCustormerDO {
	// 客户ID
	CC_SYNTHESIZE(uint64_t, custormerId, CustormerID);
	// 联系人ID
	CC_SYNTHESIZE(uint64_t, linkManId, LinkManID);
public:
	InverseCustormerDO() {
		custormerId = -1;
		linkManId = -1;
	}
};

#endif // !_INVERSE_CUSTORMER_DO_
