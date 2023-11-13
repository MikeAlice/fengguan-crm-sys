#pragma once
#pragma once

#ifndef EXPENDITURESSERVICE_H__
#define EXPENDITURESSERVICE_H__
#include "domain/dto/other_income_statement/Other_income_statementDTO.h"


class Other_income_statementService {
public:
	//删除单据			负责人：寒灯
	uint64_t removeData(const oatpp::List<DelOisDTO::Wrapper>& dto);
	//导出单据			负责人：寒灯
	std::string exporttData(const oatpp::List<ExpOisDTO::Wrapper>& dto);
	// 获取标题			负责人：寒灯
	vector<string> getTitles();
	// 获取excel文件名	负责人：寒灯
	std::string getExcelFileName();
};
#endif // EXPENDITURESSERVICE_H__
