#include "stdafx.h"
#include "ExpendituresService.h"
#include "dao/expenditures/ExpendituresDAO.h"
#include "../crm-inventory-manager/Macros.h"
#include "uselib/fastdfs/useFastDFS.h"
#include "ExcelComponent.h"
#include "uselib/excel/useExcel.h"




ExpendituresPageDTO::Wrapper ExpendituresService::listAll(const ExpendituresPageQuery::Wrapper& query)
{
	auto pages = ExpendituresPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	ExpendituresDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	pages->total = count;
	pages->calcPages();
	list<ExpendituresDO> result = dao.selectWithPage(query);

	for (ExpendituresDO sub : result) {
		auto dto = ExpendituresDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id,RecordId,type_,Type,money,Money,bank,Bank,happen_date,HappenDate,create_user,CreateUser,create_time,CreateTime,intro,Intro);
		pages->addData(dto);
	}
	return pages;
}

uint64_t ExpendituresService::addInvoice(const AddExpendituresDTO::Wrapper& dto,int creater)
{
	uint64_t id=0;
	ExpendituresAddDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RecordId, record_id, Type, type_, Money, money, Bank, bank, HappenDate, happen_date, CreateTime, create_time, Intro, intro);
	data.setCreateUser(creater);
	
	ExpendituresDAO dao;

	return dao.insert(data);

}

uint64_t ExpendituresService::removeData(const oatpp::List<DelExpendituresDTO::Wrapper>& dto)
{
	ExpendituresDAO dao;
	return dao.removeData(dto);
}

std::string ExpendituresService::exportData(const oatpp::List<ExportExpenditures::Wrapper>& dto)
{
	ExpendituresDAO dao;
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
		row.push_back(i.getType());
		row.push_back(to_string(i.getMoney()));
		row.push_back(i.getBank());
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

std::vector<std::string> ExpendituresService::getTitles()
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

std::string ExpendituresService::getExcelFileName()
{
	string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}
