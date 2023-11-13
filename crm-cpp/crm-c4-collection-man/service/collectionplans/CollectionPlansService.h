#pragma once
#ifndef _COLLECTIONPLANS_SERVICE_
#define _COLLECTIONPLANS_SERVICE_
#include <list>
#include "domain/vo/collectionplans/CollectionPlansVO.h"
#include "domain/query/collectionplans/CollectionPlansQuery.h"
#include "domain/dto/collectionplans/GetCollectionPlanListDTO.h"
#include "domain/dto/collectionplans/AddCollectionPlanDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CollectionPlansService
{
public:
	// 获取回款列表
	GetCollectionPlanListPageDTO::Wrapper listAll(const CollectionPlansQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const AddCollectionPlanDTO::Wrapper& dto, int32_t create_user_id);
};

#endif // !_COLLECTIONPLANS_SERVICE_