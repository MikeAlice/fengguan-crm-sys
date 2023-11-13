#pragma once
#ifndef _SALESCONTRACTLIST_DAO_
#define _SALESCONTRACTLIST_DAO_
#include "BaseDAO.h"
#include "domain/do/SalesContract/SalesContractDo.h"
#include "domain/query/getindex/SalesContractQuery.h"

//获取销售合同列表     负责人：归途
class querySalesContractListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SalesContractPageQuery::Wrapper& query);
	// 分页查询数据
	list<sal_contractDO> selectWithPage(const SalesContractPageQuery::Wrapper& query);
};
#endif