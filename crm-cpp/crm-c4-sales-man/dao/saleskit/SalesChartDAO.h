#pragma once

#ifndef _SALESCHART_DAO_
#define _SALESCHART_DAO_
#include"BaseDAO.h"

#include"../../domain/do/saleskit/SalesChartDO.h"

#include"../../domain/do/saleskit/NumberCountingDO.h"

using namespace oatpp;

class SalesChartDAO :public BaseDAO
{
public:
	// 统计数据条数 
	uint64_t count();
	// 依据输入时间查询销售金额排行榜数据 
	// 根据传入的date_id 来判断返回哪个时间段的排行榜
	list<SalesChartDO> selectWithAmount(const UInt64 date_id);
	// 依据输入时间查询订单总数排行榜数据
	// 根据传入的date_id 来判断返回哪个时间段的排行榜
	list<SalesChartDO> selectWithTotal(const UInt64 date_id);
};

class NumberCountingDAO :public BaseDAO
{
public:
	// 统计数据条数 
	//uint64_t count(const NumberCountingQuery::Wrapper& query);
	// 依据输入时间查询数量统计数据
	list<NumberCountingDO> selectByDate(const int date_id);
};

#endif//!_SALESCHART_DAO_

