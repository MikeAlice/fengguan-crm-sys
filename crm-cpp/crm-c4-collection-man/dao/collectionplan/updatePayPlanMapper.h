#pragma once
#ifndef _UPDATEPAYPLAN_MAPPER_
#define _UPDATEPAYPLAN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/collectionplan/updatePayPlanDO.h"

/**
 * 示例表字段匹配映射
 */
class updatePayPlanMapper : public Mapper<updatePayPlanDO>
{
public:
	updatePayPlanDO mapper(ResultSet* resultSet) const override
	{
		updatePayPlanDO data;
		data.setClientName(resultSet->getString(1));
		data.setSaleContract(resultSet->getString(1));
		data.setClientNameId(resultSet->getInt(1));
		data.setSaleContractId(resultSet->getInt(1));
		data.setTotalAmount(resultSet->getDouble(1));
		data.setNoZeroAmount(resultSet->getDouble(1));
		data.setBackAmount(resultSet->getDouble(1));
		data.setInvoiceAmount(resultSet->getDouble(1));
		data.setPlanBackDate(resultSet->getString(1));
		data.setPeriod(resultSet->getInt(1));
		data.setPlanBackAmount(resultSet->getDouble(1));
		data.setId(resultSet->getInt(1));
		return data;
	}
};

class updateConfirmPlanMapper : public Mapper<updateConfirmPlanDO>
{
public:
	updateConfirmPlanDO mapper(ResultSet* resultSet) const override
	{
		updateConfirmPlanDO data;
		data.setClientName(resultSet->getString(1));
		data.setSaleContract(resultSet->getString(1));
		data.setClientNameId(resultSet->getInt(1));
		data.setSaleContractId(resultSet->getInt(1));
		data.setTotalAmount(resultSet->getDouble(1));
		data.setNoZeroAmount(resultSet->getDouble(1));
		data.setHavePayAmount(resultSet->getDouble(1));
		data.setInvoiceAmount(resultSet->getDouble(1));
		data.setPlanBackDate(resultSet->getString(1));
		data.setPeriod(resultSet->getInt(1));
		data.setPayAmount(resultSet->getDouble(1));
		data.setId(resultSet->getInt(1));
		return data;
	}
};

#endif // !_UPDATEPAYPLAN_MAPPER_