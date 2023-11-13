#pragma once
#ifndef _COLLECTIONPLANS_DAO_
#define _COLLECTIONPLANS_DAO_
#include "BaseDAO.h"
#include "domain/query/collectionplans/CollectionPlansQuery.h"
#include "domain/do/collectionplans/GetCollectionPlanListDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class CollectionPlansDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CollectionPlansQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetCollectionPlanListDO> selectWithPage(const CollectionPlansQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<GetCollectionPlanListDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const GetCollectionPlanListDO& iObj);

};
#endif // !_COLLECTIONPLANS_DAO_
