#pragma once


#include "Mapper.h"
#include "../../domain/do/BillingRecords/BillingRecordsDO.h"

 
class BillingRecordsMapper : public Mapper<BillingRecordsDO>
{
public:
	BillingRecordsDO mapper(ResultSet* resultSet) const override
	{
		BillingRecordsDO data;
		//data.setContract_name(resultSet->getString(1));
		data.setContract_id(resultSet->getUInt64(1));
		data.setCustomer_name(resultSet->getString(2));
		data.setMoney(resultSet->getUInt64(3));
		data.setInvoice_no(resultSet->getString(4));
		data.setPay_date(resultSet->getString(5));
		data.setStages(resultSet->getUInt64(6));
		data.setName(resultSet->getString(7));
		data.setIntro(resultSet->getString(8));
		//data.setCreate_user_id(resultSet->getUInt64(9));
		return data;
	}
};