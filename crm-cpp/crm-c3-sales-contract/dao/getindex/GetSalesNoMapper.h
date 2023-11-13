#ifndef _GETSALESNO_MAPPER_
#define _GETSALESNO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/contractindex/SalesContractDO.h"

/**
 * 销售机会表字段匹配映射
 */
class GetSalesNoMapper : public Mapper<SalesContractDO>
{
public:
	SalesContractDO mapper(ResultSet* resultSet) const override
	{
		SalesContractDO data;
		//data.setContract_id(resultSet->getInt(2));
		data.setContract_no(resultSet->getString(1));
		return data;
	}
};

#endif // !_GETSALESNO_MAPPER_
