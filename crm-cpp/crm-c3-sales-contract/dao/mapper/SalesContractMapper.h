#pragma once
#ifndef _QUERY_CAPITAL_RECORD_MAPPER_
#define _QUERY_CAPITAL_RECORD_MAPPER_
#include "Mapper.h"
#include "domain/do/SalesContract/SalesContractDo.h"

class SalesContractMapper : public Mapper<sal_contractDO>
{
public:
	sal_contractDO mapper(ResultSet* resultSet) const override
	{
		sal_contractDO data;
		data.setTitle(resultSet->getString(1));
		data.setCustomer_id(resultSet->getInt(2));
		data.setMoney(resultSet->getInt(3));
		data.setBack_money(resultSet->getInt(4));
		data.setBack_status(resultSet->getInt(5));
		data.setInvoice_money(resultSet->getInt(6));
		data.setInvoice_status(resultSet->getInt(7));
		data.setStart_date(resultSet->getString(8));
		data.setEnd_date(resultSet->getString(9));
		data.setStatus(resultSet->getInt(10));
		data.setDeliver_status(resultSet->getInt(11));
		data.setCreate_time(resultSet->getString(12));
		data.setCustomer_name(resultSet->getString(13));
		data.setLinkman_name(resultSet->getString(14));
		data.setZero_money(resultSet->getInt(15));
		data.setOwe_money(resultSet->getInt(16));
		data.setContract_id(resultSet->getInt(17));
		data.setContract_no(resultSet->getString(18));
		return data;
	}
};
#endif