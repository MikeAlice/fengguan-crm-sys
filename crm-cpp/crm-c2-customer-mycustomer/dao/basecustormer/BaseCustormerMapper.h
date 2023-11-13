//2023年10月25日
//狗皮电耗子
//删除客户和投入公海的Mapper
#pragma once
#ifndef _BASECUSTORMER_MAPPER_
#define _BASECUSTORMER_MAPPER_
#include "Mapper.h"
#include "domain/do/basecustormer/BaseCustormerDO.h"

class BaseCustormerMapper : public Mapper<BaseCustormerDO>
{
public:
	BaseCustormerDO baseCustormerMapper(ResultSet *resultSet)
	{
		BaseCustormerDO data;
		data.setCustormerID(resultSet->getUInt64(1));
		return data;
	}
};
#endif // !_BASECUSTORMER_MAPPER_
