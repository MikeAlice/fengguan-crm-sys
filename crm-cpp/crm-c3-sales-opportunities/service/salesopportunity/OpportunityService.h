#pragma once
#ifndef _EXPORTSALOPPSERVICE_H_
#define _EXPORTSALOPPSERVICE_H_

#include <string>
#include <list>
#include "domain/query/getindex/OpportunityQuery.h"

/**
 * 导出销售机会Service
 * 负责人: guitu
 */
class listExportSalOppService
{
public:
	std::string exportSalOpportunity(const OpportunityQuery::Wrapper& query);
};

#endif // _EXPORTSALOPPSERVICE_H_