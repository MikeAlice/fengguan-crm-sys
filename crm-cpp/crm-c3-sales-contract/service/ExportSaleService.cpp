#include "stdafx.h"
#include "ExportSaleService.h"
#include "dao/ExportSalesDAO.h"
#include "domain/do/ExportSalesDO.h"
#include <vector>
#include "CharsetConvertHepler.h"
#include "uselib/excel/UseExcel.h"
#include "uselib/fastdfs/UseFastDfs.h"

std::string ExportSaleService::exportExportSales(const ExportSalesQuery::Wrapper& query)
{
	// Create DAO, query database
	ExportSalesDAO dao;
	// Get headers
	std::list<std::string> fields = dao.selectField("sal_contract");
	// Get all sales data
	std::list<ExportSalesDO> res = dao.selectAll(query);

	// Prepare data for export
	std::vector<std::vector<std::string>> data;
	// Prepare headers
	std::vector<std::string> header;
	for (std::string item : fields) header.push_back(item);
	header.push_back(CharsetConvertHepler::ansiToUtf8("sal_contract"));
	data.push_back(header);
	// Prepare rows
	for (ExportSalesDO item : res)
	{
		std::vector<std::string> row;

		row.push_back(item.getTitle());
		row.push_back(item.getContractId());
		row.push_back(item.getCustomerId());
	//	row.push_back(item.getName());
		row.push_back(to_string(item.getMoney()));
		row.push_back(to_string(item.getZeroMoney()));
		row.push_back(to_string(item.getBackMoney()));
		row.push_back(to_string(item.getOweMoney()));
		row.push_back(item.getBackStatus());
		row.push_back(to_string(item.getInvoiceMoney()));
		row.push_back(item.getInvoiceStatus());
		row.push_back(item.getStartDate());
		row.push_back(item.getEndDate());
		row.push_back(to_string(item.getDeliverMoney()));
		row.push_back(item.getStatus());
		row.push_back(item.getDeliverStatus());
	//	row.push_back(item.getContent());
		row.push_back(item.getContractNo());
		row.push_back(item.getLinkmanId());
		row.push_back(item.getChanceId());
		row.push_back(item.getWebsiteId());
		row.push_back(item.getOurUserId());
		row.push_back(item.getIntro());
		row.push_back(item.getRenewStatus());
		row.push_back(item.getCreateUserId());
		row.push_back(item.getCreateTime());
		row.push_back(to_string(item.getGoodsMoney()));

		data.push_back(row);
	}

	// Use Excel to write to Excel file, get file local path
	UseExcel excel;
	std::string fileName = excel.saveToExcel(data);

	// Use FastDFS to upload file and get download url
	UseFastdfs dfs;
	std::string downloadUrl = dfs.uploadFile(fileName);

	return downloadUrl;
}
