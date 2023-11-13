//2023年10月27日
//狗皮电耗子
//领取客户的service
#pragma once
#ifndef _INVERSE_CUSTORMER_
#include "dao/inversecustormer/InverseCustormerDAO.h"
#include "ApiHelper.h"
class InverseCustormerService
{
public:
	bool inverseCustormer(uint64_t custormerId, uint64_t linkManID);
};



#endif // !_INVERSE_CUSTORMER_