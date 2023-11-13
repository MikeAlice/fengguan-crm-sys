#include "stdafx.h"
#include "Out_stockController.h"
#include "service/out_stock/Out_stockService.h"


Out_StockPageJsonVO::Wrapper Out_StockController::execQueryOut_Stock(const Out_StockQuery::Wrapper& query, const PayloadDTO& payload)
{
	Out_stockService service;
	auto dto = service.listAll(query);
	auto vo = Out_StockPageJsonVO::createShared();
	vo->success(dto);
	return vo;
}

Uint64JsonVO::Wrapper Out_StockController::execAddOutStock(const AddOut_stock::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->store_name || !dto->number || !dto->status)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->store_name->empty() || dto->number < 0 || dto->status < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	Out_stockService service;
	// 执行数据新增
	uint64_t id = service.addData(dto);
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

Out_StockJsonVO::Wrapper Out_StockController::execQueryOut_StockDetails(const String& id, const PayloadDTO& payload)
{
	Out_stockService service;
	auto dto = service.queryone(id);
	auto vo = Out_StockJsonVO::createShared();
	vo->success(dto);
	return vo;
}



