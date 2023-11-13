#pragma once
#ifndef _SALESCONTRACTLIST_DAO_
#define _SALESCONTRACTLIST_DAO_
#include "BaseDAO.h"
#include "domain/do/SalesContract/SalesContractDo.h"
#include "domain/query/getindex/SalesContractQuery.h"

//��ȡ���ۺ�ͬ�б�     �����ˣ���;
class querySalesContractListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SalesContractPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<sal_contractDO> selectWithPage(const SalesContractPageQuery::Wrapper& query);
};
#endif