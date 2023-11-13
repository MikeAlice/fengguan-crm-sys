#include "stdafx.h"
#include "Other_income_statementService.h"
#include "dao/other_income_statement/Other_income_statementDAO.h"
#include "../crm-inventory-manager/Macros.h"
#include "uselib/fastdfs/useFastDFS.h"
#include "ExcelComponent.h"
#include "uselib/excel/useExcel.h"

std::string Other_income_statementService::exporttData(const oatpp::List<ExpOisDTO::Wrapper>& dto)
{
	Other_income_statementDAO dao;
	auto DOList = dao.selectWithIdList(dto);

	// 获取标题行
	auto title = getTitles();

	// 添加标题行
	vector<vector<std::string>> data{};
	data.push_back(title);

	// 添加数据行
	for (const auto& i : DOList)
	{
		vector<string> row{};
		row.push_back(to_string(i.getRecordId()));
		row.push_back(i.getTypeId());
		row.push_back(to_string(i.getMoney()));
		row.push_back(i.getBankId());
		row.push_back(i.getHappenDate());
		row.push_back(i.getCreateUser());
		row.push_back(i.getCreateTime());
		row.push_back(i.getIntro());
		data.push_back(row);
	}

	// 创建Excel并上传到Nacos
	string downloadURL = useFastDFS::useDfsWithNacos(useExcel::createExcelFile(data));

	return downloadURL;
}

vector<string> Other_income_statementService::getTitles()
{
	vector<string> title;
	title.push_back(u8"单号");
	title.push_back(u8"支出类型");
	title.push_back(u8"金额");
	title.push_back(u8"银行账号");
	title.push_back(u8"产生日期");
	title.push_back(u8"创建人");
	title.push_back(u8"创建时间");
	title.push_back(u8"描述");
	return title;
}

std::string Other_income_statementService::getExcelFileName()
{
	string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}


uint64_t Other_income_statementService::removeData(const oatpp::List<DelOisDTO::Wrapper>& dto)
{
	Other_income_statementDAO dao;
	return dao.removeData(dto);
}