#include "stdafx.h"
#include "FlowrecordService.h"
#include "../../dao/flowrecord/FlowrecordDAO.h"
#include "../crm-inventory-manager/Macros.h"
#include "uselib/fastdfs/useFastDFS.h"
#include "ExcelComponent.h"
#include "uselib/excel/useExcel.h"

FlowrecordPageDTO::Wrapper FlowrecordService::listAll(const FlowrecordPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = FlowrecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	
	// 查询数据总条数
	FlowrecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	pages->total_expenditure = dao.count_total_pay(query);
	pages->total_income = dao.count_total_rece(query);
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FlowrecordDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (FlowrecordDO sub : result)
	{
		auto dto = FlowrecordDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, bank_id, Bankid, income, Income, expenditure, Expenditure, surplus, Surplus, \
			type, Type, connect_id, Connectid, create_user, Createuser, create_time, Createtime)
			
			pages->addData(dto);
		
	}
	return pages;
}

std::string FlowrecordService::exportData(const oatpp::List<FlowrecordExportDTO::Wrapper>& dto)
{
	FlowrecordDAO dao;
	list<FlowrecordDO> DOList = dao.select2export(dto);

	// 获取标题行
	vector<string> title = { u8"银行账号",u8"收入",u8"支出",u8"余额",u8"类型",u8"关联单号",u8"创建人",u8"创建时间"};

	// 添加标题行
	vector<vector<std::string>> data{};
	data.push_back(title);

	// 添加数据行
	for (const auto& i : DOList)
	{
		vector<string> row;
		row.push_back(i.getBankid());
		row.push_back(to_string(i.getIncome()));
		row.push_back(to_string(i.getExpenditure()));
		row.push_back(to_string(i.getSurplus()));
		row.push_back(i.getType());
		row.push_back(i.getConnectid());
		row.push_back(i.getCreateuser());
		row.push_back(i.getCreatetime());
		data.push_back(row);
	}
	// 创建Excel并上传到Nacos
	string downloadURL = useFastDFS::useDfsWithNacos(useExcel::createExcelFile(data));

	return downloadURL;
}

