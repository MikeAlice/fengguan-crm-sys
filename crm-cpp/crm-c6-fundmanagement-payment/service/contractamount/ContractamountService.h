#pragma once
#ifndef _CONTRACTAMOUNT_SERVICE_
#define _CONTRACTAMOUNT_SERVICE_
#include <list>
#include "domain/vo/contractamount/ContractamountVO.h"
#include "domain/query/contractamount/ContractamountQuery.h"
#include "domain/dto/contractamount/ContractamountDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ContractamountService
{
public:
	// ��ѯ��ͬ���
	ContractamountDTO::Wrapper listAmount(const ContractamountQuery::Wrapper& query);
};

#endif // !_CONTRACTAMOUNT_SERVICE_