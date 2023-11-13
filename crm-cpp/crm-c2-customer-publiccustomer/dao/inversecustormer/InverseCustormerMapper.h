
#pragma once
#ifndef _INVERSE_CUSTORMER_MAPPER_
#define _INVERSE_CUSTORMER_MAPPER_
#include "Mapper.h"
#include "domain/do/publiccustormer/InverseCustormerDO.h"

class InverseCustormerMapper : public Mapper<InverseCustormerDO>
{
public:
	InverseCustormerDO mapper(list<ResultSet>* resultSet) {
		InverseCustormerDO data;

		for (auto item = resultSet->begin(); item != resultSet->end(); item++) {
			data.setCustormerID(item->getUInt64(1));
			data.setLinkManID(item->getUInt64(2));
		}

		return data;
	}
};

#endif // !_INVERSE_CUSTORMER_MAPPER_
