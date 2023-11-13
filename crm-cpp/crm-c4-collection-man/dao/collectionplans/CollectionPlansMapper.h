#pragma once
#ifndef _COLLECTIONPLANS_MAPPER_
#define _COLLECTIONPLANS_MAPPER_

#include "Mapper.h"
#include "domain/do/collectionplans/GetCollectionPlanListDO.h"


/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CollectionPlansMapper : public Mapper<GetCollectionPlanListDO>
{
public:
	GetCollectionPlanListDO mapper(ResultSet* resultSet) const override
	{
		GetCollectionPlanListDO data;
		data.setCustomer_name(resultSet->getString(1));
		data.setContract_name(resultSet->getString(2));
		data.setPlan_date(resultSet->getString(3));
		data.setStages(resultSet->getInt(4));
		data.setMoney(resultSet->getInt(5));
		data.setCreate_user_id(resultSet->getInt(6));
		data.setCreate_time(resultSet->getString(7));
		data.setIfpay(resultSet->getString(8));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_