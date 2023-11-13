#pragma once

#ifndef EXPENDITURESSERVICE_H__
#define EXPENDITURESSERVICE_H__

#include "domain/query/expenditures/ExpendituresQuery.h"
#include "domain/dto/expenditures/ExpendituresDTO.h"


class ExpendituresService {
public:
	//��ȡ�����б�		�����ˣ��Ǹ����
	ExpendituresPageDTO::Wrapper listAll(const ExpendituresPageQuery::Wrapper& query);
	//��������			�����ˣ��Ǹ����
	uint64_t addInvoice(const AddExpendituresDTO::Wrapper& dto, int creater);
	//ɾ������			�����ˣ�����
	uint64_t removeData(const oatpp::List<DelExpendituresDTO::Wrapper>& dto);
	//��������			�����ˣ�����
	std::string exportData(const oatpp::List<ExportExpenditures::Wrapper>& dto);
	// ��ȡ����			�����ˣ�����
	vector<string> getTitles();
	// ��ȡexcel�ļ���	�����ˣ�����
	std::string getExcelFileName();
};
#endif // EXPENDITURESSERVICE_H__
