#pragma once
#include <string>
#include <list>
#include "domain/query/ExportSalesQUERY.h"

/**
 * �������ۻ���Service
 * ������: ����
 */
class ExportSaleService
{
public:
	std::string exportExportSales(const ExportSalesQuery::Wrapper& query);
};