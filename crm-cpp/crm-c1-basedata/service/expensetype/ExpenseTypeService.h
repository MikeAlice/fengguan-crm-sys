#pragma once
#ifndef _EXPENSETYPE_SERVICE_
#define _EXPENSETYPE_SERVICE_
#include <list>
#include "domain/vo/expensetype/ExpenseTypeVO.h"
#include "domain/query/expensetype/ExpenseTypeQuery.h"
#include "domain/dto/expensetype/ExpenseTypeDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ExpenseTypeService
{
public:
	// ��ҳ��ѯ��������
	ExpenseTypePageDTO::Wrapper listAll(const ExpenseTypeQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ExpenseTypeDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ExpenseTypeDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};
/**
 * �����������ͷ���ʵ��
 */
class ExpenseService
{
public:

	//��ѯ�ṹ��
	ExpenseTreeJsonVO::Wrapper listTree(const ExpenseQuery::Wrapper& query);

};

#endif // !_EXPENSETYPE_SERVICE_