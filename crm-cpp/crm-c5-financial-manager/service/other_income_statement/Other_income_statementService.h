#pragma once
#pragma once

#ifndef EXPENDITURESSERVICE_H__
#define EXPENDITURESSERVICE_H__
#include "domain/dto/other_income_statement/Other_income_statementDTO.h"


class Other_income_statementService {
public:
	//ɾ������			�����ˣ�����
	uint64_t removeData(const oatpp::List<DelOisDTO::Wrapper>& dto);
	//��������			�����ˣ�����
	std::string exporttData(const oatpp::List<ExpOisDTO::Wrapper>& dto);
	// ��ȡ����			�����ˣ�����
	vector<string> getTitles();
	// ��ȡexcel�ļ���	�����ˣ�����
	std::string getExcelFileName();
};
#endif // EXPENDITURESSERVICE_H__
