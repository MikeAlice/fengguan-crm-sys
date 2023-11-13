#pragma once

#ifndef _OUT_BOUND_MAPPER_
#define _OUT_BOUND_MAPPER_

#include "Mapper.h"
#include "../../domain/do/out_bound/Out_boundDO.h"

/**
 * 出库单数据表字段匹配映射
 */
class Out_boundMapper : public Mapper<Out_boundDO>
{
public:
	Out_boundDO mapper(ResultSet* resultSet) const override
	{
		Out_boundDO data;
		data.setOut_id(resultSet->getUInt64(1));
		data.setStore_id(resultSet->getUInt64(2));
		data.setContract_id(resultSet->getUInt64(3));
		data.setTitle(resultSet->getString(4));
		data.setMoney(resultSet->getDouble(5));
		data.setNumber(resultSet->getUInt64(6));
		data.setIntro(resultSet->getString(7));
		data.setStatus(resultSet->getUInt64(8));
		data.setOut_user_id(resultSet->getUInt64(9));
		data.setOut_time(resultSet->getString(10));
		data.setOut_type(resultSet->getString(11));
		data.setCreate_user_id(resultSet->getUInt64(12));
		data.setCreate_time(resultSet->getString(13));
		return data;
	}
};

#endif // !_OUT_BOUND_MAPPER_