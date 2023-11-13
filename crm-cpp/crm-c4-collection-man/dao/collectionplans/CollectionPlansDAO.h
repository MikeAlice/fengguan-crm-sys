#pragma once
#ifndef _COLLECTIONPLANS_DAO_
#define _COLLECTIONPLANS_DAO_
#include "BaseDAO.h"
#include "domain/query/collectionplans/CollectionPlansQuery.h"
#include "domain/do/collectionplans/GetCollectionPlanListDO.h"


/**
 * 示例表数据库操作实现
 */
class CollectionPlansDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CollectionPlansQuery::Wrapper& query);
	// 分页查询数据
	list<GetCollectionPlanListDO> selectWithPage(const CollectionPlansQuery::Wrapper& query);
	// 通过姓名查询数据
	//list<GetCollectionPlanListDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const GetCollectionPlanListDO& iObj);

};
#endif // !_COLLECTIONPLANS_DAO_
