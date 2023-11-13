//2023��10��25��
//��Ƥ�����
//ɾ���ͻ���Ͷ�빫����Mapper
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
