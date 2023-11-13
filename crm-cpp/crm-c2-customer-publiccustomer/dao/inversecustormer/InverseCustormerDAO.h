//2023年10月23日
//狗皮电耗子
//领取客户的DAO
#pragma once
#ifndef _INVERSE_CUSTORMER_DAO_
#define _INVERSE_CUSTORMER_DAO_
#include "BaseDAO.h"
#include "dao/inversecustormer/InverseCustormerDAO.h"

class InverseCustormerDAO : public BaseDAO
{
public:
	bool InverseCustormerById(uint64_t id, uint64_t linkManID);
};
#endif // !_INVERSE_CUSTORMER_DAO_



