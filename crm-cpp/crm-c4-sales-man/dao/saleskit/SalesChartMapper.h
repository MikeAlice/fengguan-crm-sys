#pragma once

#ifndef _SALESCHART_MAPPER_
#define _SALESCHART_MAPPER_

#include"Mapper.h"
#include"../../domain/do/saleskit/NumberCountingDO.h"
#include"../../domain/do/saleskit/SalesChartDO.h"


/**
* ±Ì◊÷∂Œ∆•≈‰”≥…‰
*/
class SalesChartMapper :public Mapper<SalesChartDO>
{
public:
	SalesChartDO mapper(ResultSet* resultSet)const override
	{
		SalesChartDO data;
		data.setRank(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setAmount(resultSet->getUInt64(3));
		data.setTotal(resultSet->getUInt64(4));
		return data;
	}
};


class NumberCountingMapper :public Mapper<NumberCountingDO>
{
public:
	NumberCountingDO mapper(ResultSet* resultSet)const override
	{
		NumberCountingDO data;
		data.setNewly_add_business_opportunity(resultSet->getUInt64(2));
		data.setNewly_add_contract(resultSet->getUInt64(3));
		data.setNewly_add_follow_up_records(resultSet->getUInt64(4));
		data.setNewly_add_contact_people(resultSet->getUInt64(5));
		data.setNewly_add_contract_amount(resultSet->getUInt64(6));
		data.setNewly_add_collection_amount(resultSet->getUInt64(7));
		return data;
	}
};

#endif//!_SALESCHART_MAPPER_
