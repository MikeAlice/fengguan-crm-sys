#pragma once
/*
* 负责人：老菌
*/
#ifndef _IMPORTCUSTOMER_MAPPER_
#define _IMPORTCUSTOMER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/fieldext/FieldExtDO.h"

/**
 * 系统用户信息表字段匹配映射
 */
class GetFieldExtMapper : public Mapper<FieldExtDO>
{
public:
	FieldExtDO mapper(ResultSet* resultSet) const override
	{
		FieldExtDO data;
		data.setVisible(resultSet->getInt(1));
		return data;
	}
};

#endif // !_EXPORTCUSTOMER_MAPPER_