#pragma once
#ifndef _EXPORTSALOPPDAO_H_
#define _EXPORTSALOPPDAO_H_

#include "BaseDAO.h"
#include <list>
#include <vector>
#include "domain/query/getindex/OpportunityQuery.h"
#include "domain/do/Sales/Cst_chanceDO.h"

class ExportSalOppDAO : public BaseDAO
{
public:
	// 获取导出数据
	std::list<Cst_chanceDO> selectAll(const OpportunityQuery::Wrapper& query);
	// 获取表头
	std::list<std::string> selectField(const std::string& table);
};

#endif // !_EXPORTSALOPPDAO_H_