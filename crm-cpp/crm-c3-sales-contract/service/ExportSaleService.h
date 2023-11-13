#pragma once
#include <string>
#include <list>
#include "domain/query/ExportSalesQUERY.h"

/**
 * 导出销售机会Service
 * 负责人: 科文
 */
class ExportSaleService
{
public:
	std::string exportExportSales(const ExportSalesQuery::Wrapper& query);
};