#pragma once

#ifndef _GETAMOUNTINFO_MAPPER_
#define _GETAMOUNTINFO_MAPPER_

#include "Mapper.h"
#include <domain/do/paybackmanage/PaybackInfoDO.h>

/**
 * 示例表字段匹配映射
 */
class GetAmountInfoMapper : public Mapper<PaybackInfoDO>
{
public:
	PaybackInfoDO mapper(ResultSet* resultSet) const override
	{
		PaybackInfoDO data;
		data.setTamo(resultSet->getDouble(1) * 1000);
		data.setZamo(resultSet->getDouble(2) * 1000);
		data.setRamo(resultSet->getDouble(3) * 1000);
		data.setIamo(resultSet->getDouble(4) * 1000);
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_