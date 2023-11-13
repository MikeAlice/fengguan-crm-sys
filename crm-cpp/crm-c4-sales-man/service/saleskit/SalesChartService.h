#pragma once

#ifndef _SALESCHART_SERVICE_
#define _SALESCHART_SERVICE_
#include<list>

#include"domain/vo/saleskit/SalesChartVO.h"
#include"domain/dto/saleskit/SalesChartDTO.h"
#include"domain/query/saleskit/SalesChartQuery.h"

#include"domain/vo/saleskit/NumberCountingVO.h"
#include"domain/dto/saleskit/NumberCountingDTO.h"
#include"domain/query/saleskit/NumberCountingQuery.h"

/**
* 销售榜服务
*/
class SalesChartService
{
public:
	// 查询排行榜数据
	SalesChartDTO::Wrapper listRank(const UInt64 date_id);
};

/**
* 数量统计服务
*/
class NumberCountingService
{
public:
	//查询数量统计数据
	NumberCountingDTO::Wrapper listNumberCount(const UInt64 date_id);
};

#endif //!_SALESCHART_SERVICE_