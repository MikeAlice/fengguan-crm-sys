#pragma once
/*
* 负责人：老菌
*/
#ifndef _EXPORTCUSTOMER_MAPPER_
#define _EXPORTCUSTOMER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/customer/CustomerDO.h"

/**
 * 客户信息表字段匹配映射
 */
class ExportCustomerMapper : public Mapper<CustomerDO>
{
public:
	CustomerDO mapper(ResultSet* resultSet) const override
	{
		CustomerDO data;
		data.setCustomer_Id(resultSet->getUInt(1));
		data.setName(resultSet->getString(2));
		data.setCustomer_No(resultSet->getString(3));
		data.setCreate_User_Id(resultSet->getInt(4));
		data.setOwner_User_Id(resultSet->getInt(5));
		data.setCreate_Time(resultSet->getString(6));
		data.setNext_Time(resultSet->getString(7));
		data.setConn_Time(resultSet->getString(8));
		data.setConn_Body(resultSet->getString(9));
		data.setLinkman(resultSet->getString(10));
		data.setSource(resultSet->getString(11));
		data.setGrade(resultSet->getString(12));
		data.setIndustry(resultSet->getString(13));
		data.setMobile(resultSet->getString(14));
		data.setTel(resultSet->getString(15));
		data.setAddress(resultSet->getString(16));
		data.setIntro(resultSet->getString(17));
		data.setNeeds(resultSet->getString(18));
		data.setCreate_User_Name(resultSet->getString(19));
		data.setOwner_User_Name(resultSet->getString(20));
		return data;
	}
};

#endif // !_EXPORTCUSTOMER_MAPPER_
