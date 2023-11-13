#pragma once

#ifndef EXPENDITURESSERVICE_H__
#define EXPENDITURESSERVICE_H__

#include "domain/query/expenditures/ExpendituresQuery.h"
#include "domain/dto/expenditures/ExpendituresDTO.h"


class ExpendituresService {
public:
	//获取单据列表		负责人：是个天才
	ExpendituresPageDTO::Wrapper listAll(const ExpendituresPageQuery::Wrapper& query);
	//新增单据			负责人：是个天才
	uint64_t addInvoice(const AddExpendituresDTO::Wrapper& dto, int creater);
	//删除单据			负责人：云隐
	uint64_t removeData(const oatpp::List<DelExpendituresDTO::Wrapper>& dto);
	//导出单据			负责人：云隐
	std::string exportData(const oatpp::List<ExportExpenditures::Wrapper>& dto);
	// 获取标题			负责人：云隐
	vector<string> getTitles();
	// 获取excel文件名	负责人：云隐
	std::string getExcelFileName();
};
#endif // EXPENDITURESSERVICE_H__
