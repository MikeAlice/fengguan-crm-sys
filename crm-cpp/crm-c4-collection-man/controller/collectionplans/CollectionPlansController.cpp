#include "stdafx.h"
#include "CollectionPlansController.h"
#include <service/collectionplans/CollectionPlansService.h>

CollectionPlansPageJsonVO::Wrapper CollectionPlansController::execQueryCollection(const CollectionPlansQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	CollectionPlansService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CollectionPlansPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper CollectionPlansController::execAddCollectionPlans(const AddCollectionPlanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->customer_id || !dto->name || !dto->contract_name || !dto->backdate || !dto->stages || !dto->money || !dto->contract_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->customer_id < 0 || dto->name->empty() || dto->contract_name->empty() || dto->backdate->empty() || dto->stages <= 0 || dto->money < 0 || dto->contract_id < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 获取当前用户信息
	Int32 create_user_id = atoi(payload.getId().c_str());
	// 定义一个Service
	CollectionPlansService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, create_user_id);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
