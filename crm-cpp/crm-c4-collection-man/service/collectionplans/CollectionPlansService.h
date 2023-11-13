#pragma once
#ifndef _COLLECTIONPLANS_SERVICE_
#define _COLLECTIONPLANS_SERVICE_
#include <list>
#include "domain/vo/collectionplans/CollectionPlansVO.h"
#include "domain/query/collectionplans/CollectionPlansQuery.h"
#include "domain/dto/collectionplans/GetCollectionPlanListDTO.h"
#include "domain/dto/collectionplans/AddCollectionPlanDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CollectionPlansService
{
public:
	// ��ȡ�ؿ��б�
	GetCollectionPlanListPageDTO::Wrapper listAll(const CollectionPlansQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const AddCollectionPlanDTO::Wrapper& dto, int32_t create_user_id);
};

#endif // !_COLLECTIONPLANS_SERVICE_