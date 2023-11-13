#pragma once
#ifndef _DICTCLASSIFY_MAPPER_
#define _DICTCLASSIFY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dictclassify/DictClassifyDO.h"


class DictClassifyMapper : public Mapper<DictClassifyDO>
{
public:
	DictClassifyDO mapper(ResultSet* resultSet) const override
	{
		DictClassifyDO data;
		data.setId(resultSet->getUInt64(1));
		data.setTypeName(resultSet->getString(2));
		data.setTypedir(resultSet->getString(3));
		data.setTypetag(resultSet->getString(4));
		data.setSort(resultSet->getUInt64(5));
		data.setVisible(resultSet->getUInt64(6));
		data.setIntro(resultSet->getString(7));
		data.setSeotitle(resultSet->getUInt64(8));
		data.setKeywords(resultSet->getUInt64(9));

		return data;
	}
};
class DictClassifyListMapper : public Mapper<DictClassifyListDO>
{
public:
	DictClassifyListDO mapper(ResultSet* resultSet) const override
	{
		DictClassifyListDO data;
		data.setId(resultSet->getUInt64(1));
		data.setTypeName(resultSet->getString(2));
		data.setTypetag(resultSet->getString(3));
		return data;
	}
};
#endif // !_DICTCLASSIFY_MAPPER_
