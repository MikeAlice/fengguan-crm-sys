#pragma once
#ifndef _GetCustomer_MAPPER_
#define _GetCustomer_MAPPER_

#include "Mapper.h"
#include "domain/do/getcustomer/GetCustomerDO.h"

/**
 * cst_customer表字段匹配映射
 */
class GetCustomerMapper : public Mapper<GetCustomerDO>
{
public:
	GetCustomerDO mapper(ResultSet* resultSet) const override
	{
		GetCustomerDO data;
		data.setName(resultSet->getString(1));
		data.setCustomer_Id(resultSet->getUInt64(2));
		data.setOwner_User_Id(resultSet->getInt(3));
		data.setConn_Time(resultSet->getString(4));
		data.setConn_Body(resultSet->getString(5));
		data.setNext_Time(resultSet->getString(6));
		return data;
	}
};

#endif // !_GetCustomer_MAPPER_