#pragma once
#ifndef _SALES_OPPORTUNITY_DAO_
#define _SALES_OPPORTUNITY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/salesopportunity/SalesOpportunityDO.h"
#include "../../domain/query/salesopportunity/SalesOpportunityQuery.h"

/**
 * 示例表数据库操作实现
 */
class SalesOpportunityDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const SalesOpportunityDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	// 新增数据
	int insert(const SalesOpportunityDO& uObj);
};
#endif // !_SALES_OPPORTUNITY_DAO_
