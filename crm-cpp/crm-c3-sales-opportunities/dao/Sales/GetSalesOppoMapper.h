#ifndef _GETSALESOPPO_MAPPER_
#define _GETSALESOPPO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Sales/Cst_chanceDO.h"

/**
 * 销售机会表字段匹配映射
 */
class GetSalesOppoMapper : public Mapper<Cst_chanceDO>
{
public:
	Cst_chanceDO mapper(ResultSet* resultSet) const override
	{
		Cst_chanceDO data;
		data.setName(resultSet->getString(1));
		data.setChance_id(resultSet->getInt(2));
		return data;
	}
};

#endif // !_GETSALESOPPO_MAPPER_
