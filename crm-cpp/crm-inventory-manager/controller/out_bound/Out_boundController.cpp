#include "stdafx.h"
#include"Out_boundController.h"
#include "service/out_bound/Out_boundService.h"




BooleanJsonVO::Wrapper Out_boundController::execConfirmOutstock(const ConfOut_boundDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	if (!dto->out_id || dto->out_id <= 0 || dto->status == 1 || dto->number <= 0 )//出库单单号不合法、出库单状态为已出库、或出库数量非正数
	{
		jvo->init(Boolean(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	Out_boundService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// 响应结果
	return jvo;
}

BooleanJsonVO::Wrapper Out_boundController::execDeleteOutstock(const List<DelOut_boundDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = BooleanJsonVO::createShared();
	// 对列表进行校验
	if (!dto)
	{
		jvo->init(Boolean(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//对列表参数逐个检验
	for (auto i = dto->begin(); i != dto->end(); i++)
	{	
		if (!((*i)->out_id) || (*i)->out_id.getValue({}) <= 0)
		{
			jvo->init(Boolean(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// 定义一个Service
	Out_boundService service;
	// 执行数据删除
	if (service.removeData(dto)){
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// 响应结果
	return jvo;
}


