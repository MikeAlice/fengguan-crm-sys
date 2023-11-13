#include "stdafx.h"
#include "DelPayPlanController.h"
#include "../../service/paybackmanage/DelPayPlan_GetAmountInfoService.h"


Uint64JsonVO::Wrapper DelPayPlanController::execDelPayPlan(const DeletePayPlanDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	auto cur = dto->listid.getPtr(); //获取到领域模型内变量的指针

	//参数检验------------------------------------------------------------
	if (cur->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto i = cur->begin(); i != cur->end(); i++)
	{
		if ((*i) == 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//参数检验完毕------------------------------------------------------


	// 定义一个Service
	DelPayPlan_GetAmountInfoService service;
	//执行数据删除

	for (auto i = cur->begin(); i != cur->end(); i++)
	{
		if (service.removeData((*i).getValue(0))) {
			jvo->success((*i));
		}
		else
		{
			jvo->fail((*i));
		}
	}

	// 响应结果
	return jvo;
}
