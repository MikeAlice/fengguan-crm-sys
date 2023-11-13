#pragma once
#ifndef _QUERYSALESOPPORTUNITY_MAPPER_
#define _QUERYSALESOPPORTUNITY_MAPPER_
#include "Mapper.h"
#include "domain/do/Sales/Cst_chanceDO.h"

class SalOppListMapper : public Mapper<Cst_chanceDO>
{
public:
	Cst_chanceDO mapper(ResultSet* resultSet) const override
	{
		Cst_chanceDO data;
		data.setName(resultSet->getString(1));
		data.setCustomer_id(resultSet->getInt(2));
		data.setFind_date(resultSet->getString(3));
		data.setBill_date(resultSet->getString(4));
		data.setMoney(resultSet->getInt(5));
		data.setSalestage(resultSet->getInt(6));
		data.setIntro(resultSet->getString(7));
		data.setCreate_time(resultSet->getString(8));
		data.setCustomer_name(resultSet->getString(9));
		data.setLinkman_name(resultSet->getString(10));
		data.setChance_id(resultSet->getInt(11));
		return data;
	}
};
#endif