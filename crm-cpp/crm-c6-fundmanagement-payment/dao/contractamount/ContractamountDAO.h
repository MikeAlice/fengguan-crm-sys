#pragma once
#ifndef _CONTRACTAMOUNT_DAO_
#define _CONTRACTAMOUNT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contractamount/ContractamountDO.h"
#include "../../domain/query/contractamount/ContractamountQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ContractamountDAO : public BaseDAO
{
public:
	//��ѯ�ܽ��
	uint64_t getTotal(const ContractamountQuery::Wrapper& query);
	//��ѯȥ����
	uint64_t getZero(const ContractamountQuery::Wrapper& query);
	//��ѯ�Ѹ����
	uint64_t getPaid(const ContractamountQuery::Wrapper& query);
	//��ѯ���շ�Ʊ���
	uint64_t getInvoice(const ContractamountQuery::Wrapper& query);
};
#endif // !_CONTRACTAMOUNT_DAO_