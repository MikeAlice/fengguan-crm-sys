#pragma once
#ifndef _SALOPPLIST_DAO_
#define _SALOPPLIST_DAO_
#include "BaseDAO.h"
#include "domain/do/Sales/Cst_chanceDO.h"
#include "domain/query/saleopport/SaleopportQuery.h"

//获取销售机会列表     负责人：归途
class querySalOppListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SaleopportPageQuery::Wrapper& query);
	// 分页查询数据
	list<Cst_chanceDO> selectWithPage(const SaleopportPageQuery::Wrapper& query);
};
#endif