#ifndef _GETCUSTOMERNAME_MAPPER_
#define _GETCUSTOMERNAME_MAPPER_

#include "Mapper.h"
#include "domain/do/getcustomername/GetCustomerNameDO.h"

/**
 * cst_customer表字段匹配映射
 */
class GetCustomerNameMapper : public Mapper<GetCustomerNameDO>
{
public:
	GetCustomerNameDO mapper(ResultSet* resultSet) const override
	{
		GetCustomerNameDO data;
		data.setName(resultSet->getString(1));
		data.setCustomer_Id(resultSet->getUInt(2));
		return data;
	}
};

#endif // !_GETCUSTOMERNAME_MAPPER_
