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
	// ͳ���������� 
	uint64_t count();
	// ��������ʱ���ѯ���۽�����а����� 
	// ���ݴ����date_id ���жϷ����ĸ�ʱ��ε����а�
	list<SalesChartDO> selectWithAmount(const UInt64 date_id);
	// ��������ʱ���ѯ�����������а�����
	// ���ݴ����date_id ���жϷ����ĸ�ʱ��ε����а�
	list<SalesChartDO> selectWithTotal(const UInt64 date_id);
};

class NumberCountingDAO :public BaseDAO
{
public:
	// ͳ���������� 
	//uint64_t count(const NumberCountingQuery::Wrapper& query);
	// ��������ʱ���ѯ����ͳ������
	list<NumberCountingDO> selectByDate(const int date_id);
};

#endif//!_SALESCHART_DAO_

