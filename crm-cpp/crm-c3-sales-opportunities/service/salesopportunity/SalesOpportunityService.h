#pragma once
#ifndef _SALES_OPPORTUNITY_SERVICE_
#define _SALES_OPPORTUNITY_SERVICE_
#include <list>
#include "domain/vo/salesopportunity/SalesOpportunityVO.h"
#include "domain/query/salesopportunity/SalesOpportunityQuery.h"
#include "domain/dto/salesopportunityinfo/DeleteSalesOpDTO.h"
#include "domain/dto/salesopportunityinfo/UpdateSalesOpDTO.h"
#include "domain/dto/salesopportunityinfo/InsertSalesOpDTO.h"

/**
 * 销售机会相关服务实现，包括数据删除、数据修改等
 */
class SalesOpportunityService
{
public:
	// 修改数据
	bool updateData(const UpdateSalesOpDTO::Wrapper& dto);
	// 通过ID删除数据
	bool deleteData(uint64_t id);
	// 新增数据
	bool insertData(const InsertSalesOpDTO::Wrapper& dto);
};

#endif // !_SALES_OPPORTUNITY_SERVICE_