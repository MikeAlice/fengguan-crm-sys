#pragma once
#include "Mapper.h"
#include "../../domain/do/collectionrecord/CollectionRecordDO.h"

class CollectionRecordMapper : public Mapper<CollectionRecordDO>
{
public:
	CollectionRecordDO mapper(ResultSet* resultSet) const override
	{
		CollectionRecordDO data;
		
		data.setback_date(resultSet->getString(1));
		data.setbank_id(resultSet->getInt(2));
		data.setbus_type(resultSet->getString(3));
		data.setcontract_id(resultSet->getInt(4));
		data.setcontract_name(resultSet->getString(5));
		data.setcreate_time(resultSet->getString(6));
		data.setcustomer_id(resultSet->getInt(7));
		data.setcustomer_name(resultSet->getString(8));
		data.setmoney(resultSet->getUInt64(9));
		data.setplan_id(resultSet->getInt(10));
		data.setrecord_id(resultSet->getInt(11));
		data.setstages(resultSet->getInt(12));
		data.setzero_money(resultSet->getUInt64(13));
		return data;
	}
};