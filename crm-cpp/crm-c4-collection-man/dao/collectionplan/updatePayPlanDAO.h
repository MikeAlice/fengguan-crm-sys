#pragma once
#ifndef _UPDATEPAYPLAN_DAO_
#define _UPDATEPAYPLAN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/collectionplan/updatePayPlanDO.h"

// 修改回款计划
class updatePayPlanDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const updatePayPlanDO& uObj);
};

// 确认回款计划
class updateConfirmPlanDAO : public BaseDAO
{
public:
	//修改数据
	int update(const updateConfirmPlanDO& uObj);
};
#endif // !_UPDATEPAYPLAN_DAO_
