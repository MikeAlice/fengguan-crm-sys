#pragma once
#ifndef FlowrecordMAPPER_H__
#define FlowrecordMAPPER_H__

#include "Mapper.h"
#include "../../domain/do/flowrecord/FlowrecordDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class FlowrecordMapper : public Mapper<FlowrecordDO>
{
public:
	FlowrecordDO mapper(ResultSet* resultSet) const override
	{
		FlowrecordDO data;
		data.setBankid(resultSet->getString(1));
		data.setIncome(resultSet->getDouble(2));
		data.setExpenditure(resultSet->getDouble(3));
		data.setSurplus(resultSet->getDouble(4));
		data.setType(resultSet->getString(5));
		data.setConnectid(resultSet->getString(6));
		data.setCreateuser(resultSet->getString(7));
		data.setCreatetime(resultSet->getString(8));
		/*data.setTotalincome(resultSet->getInt(9));
		data.setTotalexpenditure(resultSet->getInt(10));*/
		return data;
	}
};
class DoubleMapper : public Mapper<double> {
public:
	double mapper(ResultSet* resultSet) const override
	{
		double data = resultSet->getDouble(1);
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_