#pragma once
/*
* 负责人：老菌
*/
#ifndef _IMPORTCUSTOMER_MAPPER_
#define _IMPORTCUSTOMER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/customer/CustomerDO.h"

/**
 * 系统用户信息表字段匹配映射
 */
class ImportCustomerMapper : public Mapper<CustomerDO>
{
public:
	CustomerDO mapper(ResultSet* resultSet) const override
	{
		CustomerDO data;
		data.setName(resultSet->getString(1));
		data.setCreate_User_Id(resultSet->getInt(2));
		data.setOwner_User_Id(resultSet->getInt(3));
		data.setCreate_Time(resultSet->getString(4));
		data.setNext_Time(resultSet->getString(5));
		data.setConn_Time(resultSet->getString(6));
		data.setConn_Body(resultSet->getString(7));
		return data;
	}
};

#endif // !_EXPORTCUSTOMER_MAPPER_