#include "stdafx.h"
#include "InvoiceController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/invoice/InvoiceService.h"
#include "../../domain/dto/invoice/InvoiceAddDTO.h"

InvoicePageJsonVO::Wrapper InvoiceController::execQueryInvoice(const InvoiceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	InvoiceService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InvoicePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper InvoiceController::execAddInvoice(const InvoiceAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->customer_name || !dto->contract_name || !dto->money )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->customer_name->empty() || dto->contract_name->empty() || dto->money<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	InvoiceService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, stoi(payload.getId()));
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