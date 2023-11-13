#pragma once
#ifndef _UPDATEPAYPLAN_SERVICE_
#define _UPDATEPAYPLAN_SERVICE_
#include "domain/dto/collectionplan/updatePayPlanDTO.h"
#include "domain/dto/collectionplan/updateConfirmPlanDTO.h"

class updatePayPlanService
{
public:
	// 修改数据
	bool updateData(const updatePayPlanDTO::Wrapper& dto);
};

class updateConfirmPlanService
{
public:
	bool updateData(const updateConfirmPlanDTO::Wrapper& dto);
};

#endif 

