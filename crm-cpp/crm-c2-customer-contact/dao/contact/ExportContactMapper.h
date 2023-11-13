#pragma once

#ifndef _EXPORTCONTACT_MAPPER_
#define _EXPORTCONTACT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/contact/ContactDO.h"

/**
 * 客户信息表字段匹配映射
 */
class ExportCustomerMapper : public Mapper<ContactDO>
{
public:
	ContactDO mapper(ResultSet* resultSet) const override
	{
		ContactDO data;
		data.setCustomer_name(resultSet->getString(1));
		data.setLinkman_name(resultSet->getString(2));
		data.setGender(resultSet->getUInt(3));
		data.setPostion(resultSet->getString(4));
		data.setTel(resultSet->getString(5));
		data.setMobile(resultSet->getString(6));
		data.setQicq(resultSet->getString(7));
		data.setEmail(resultSet->getString(8));
		data.setZipcode(resultSet->getString(9));
		data.setAddress(resultSet->getString(10));
		data.setIntro(resultSet->getString(11));
		data.setOwner_user_name(resultSet->getString(12));
		data.setCreate_time(resultSet->getString(13));
		return data;
	}
};

#endif // !_EXPORTCONTACT_MAPPER_