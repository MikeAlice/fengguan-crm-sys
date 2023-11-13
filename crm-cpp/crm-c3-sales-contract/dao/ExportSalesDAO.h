#pragma once

#ifndef _EXPORT_SALES_DAO_
#define _EXPORT_SALES_DAO_

#include "BaseDAO.h"
#include <list>
#include <vector>
#include "domain/query/ExportSalesQUERY.h"
#include "domain/do/ExportSalesDO.h"

class ExportSalesDAO : public BaseDAO
{
public:
	// Retrieve all sales
	std::list<ExportSalesDO> selectAll(const ExportSalesQuery::Wrapper& query);
	// Retrieve headers
	std::list<std::string> selectField(const std::string& table);
};

#endif 