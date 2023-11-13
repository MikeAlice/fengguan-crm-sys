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
* ���۰����
*/
class SalesChartService
{
public:
	// ��ѯ���а�����
	SalesChartDTO::Wrapper listRank(const UInt64 date_id);
};

/**
* ����ͳ�Ʒ���
*/
class NumberCountingService
{
public:
	//��ѯ����ͳ������
	NumberCountingDTO::Wrapper listNumberCount(const UInt64 date_id);
};

#endif //!_SALESCHART_SERVICE_