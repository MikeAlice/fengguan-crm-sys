#include "stdafx.h"
#include "UpdatePayPlanController.h"
#include "../../service/update-pay-plan/UpdatePayPlanService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper UpdatePayPlanController::execupdatePayPlan(const UpdatePayPlanDTO::Wrapper& dto) {
	/*auto result = StringJsonVO::createShared();
	result->success(String("add pay record !"));
	return result;*/
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->contract_name ||  !dto->supplier_name || !dto->money || !dto->stages)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (stof(dto->money) < 0.0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	UpdatePayPlanService service;
	// 执行数据新增
	uint64_t id = service.dealWithResult(dto);
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