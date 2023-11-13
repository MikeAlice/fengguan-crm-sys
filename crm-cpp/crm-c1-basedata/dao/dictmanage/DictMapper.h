
#ifndef _DICT_MAPPER_
#define _DICT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dictmanage/DictDO.h"
#include "../../domain/do/dictmanage/DictTypeDO.h"

/**
 * ×Ö¶ÎÆ¥ÅäÓ³Éä-×Öµä¹ÜÀí
 */
class DictMapper : public Mapper<DictDO>
{
public:
	DictDO mapper(ResultSet* resultSet) const override
	{
		DictDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setTypetag(resultSet->getString(3));
		data.setSort(resultSet->getInt(4));
		data.setVisible(resultSet->getInt(5));
		return data;
	}
};

class DictTypeMapper : public Mapper<DictTypeDO>
{
public:
	DictTypeDO mapper(ResultSet* resultSet) const override
	{
		DictTypeDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};
#endif // !_DICT_MAPPER_