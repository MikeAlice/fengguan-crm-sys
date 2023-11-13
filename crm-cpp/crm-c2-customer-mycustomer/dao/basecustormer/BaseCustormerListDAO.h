//删除客户与投入公海的DAO
//狗皮电耗子
//2023年10月25日
#pragma once
#ifndef _BASECUSTORMER_DAO_
#define _BASECUSTORMER_DAO_
#include "BaseDAO.h"
#include "domain/do/basecustormer/BaseCustormerDO.h"

class BaseCustormerDAO : public BaseDAO
{
public:
	bool deleteByCustormerId(uint64_t id);
	bool hightseaByCustormerId(uint64_t id);
};

#endif // !_BASECUSTORMER_DAO_