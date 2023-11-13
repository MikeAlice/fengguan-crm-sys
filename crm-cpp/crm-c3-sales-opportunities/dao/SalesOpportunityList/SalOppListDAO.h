#pragma once
#ifndef _SALOPPLIST_DAO_
#define _SALOPPLIST_DAO_
#include "BaseDAO.h"
#include "domain/do/Sales/Cst_chanceDO.h"
#include "domain/query/saleopport/SaleopportQuery.h"

//��ȡ���ۻ����б�     �����ˣ���;
class querySalOppListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SaleopportPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<Cst_chanceDO> selectWithPage(const SaleopportPageQuery::Wrapper& query);
};
#endif