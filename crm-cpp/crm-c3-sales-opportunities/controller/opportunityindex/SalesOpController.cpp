#include "stdafx.h"
#include "SalesOpController.h"
#include "../../service/salesopportunity/SalesOpportunityService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper SalesOpController::execRemoveSalesOp(const DeleteSalesOpDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->chance_id || dto->chance_id < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SalesOpportunityService service;
	// 执行数据删除
	if (service.deleteData(dto->chance_id.getValue(0))) {
		jvo->success(UInt64(dto->chance_id));
	}
	else
	{
		jvo->fail(UInt64(dto->chance_id));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper SalesOpController::execModifySalesOp(const UpdateSalesOpDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->chance_id || dto->chance_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->customer_id || dto->customer_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->linkman_id || dto->linkman_id == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(dto->find_date == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(dto->bill_date == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->salestage || dto->salestage <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->money || dto->money <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->success_rate || dto->success_rate <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->userID || dto->userID <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(dto->name == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(dto->intro == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->status || dto->status <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(!dto->create_user_id || dto->create_user_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(dto->create_time == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SalesOpportunityService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(UInt64(dto->chance_id));
	}
	else
	{
		jvo->fail(UInt64(dto->chance_id));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper SalesOpController::execAddSalesOp(const InsertSalesOpDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->customer_id || dto->customer_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->linkman_id || dto->linkman_id == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->find_date == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->bill_date == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->salestage || dto->salestage <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->money || dto->money <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->success_rate || dto->success_rate <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->userID || dto->userID <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->name == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->intro == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->status || dto->status <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->create_user_id || dto->create_user_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->create_time == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SalesOpportunityService service;
	// 新增数据
	uint64_t id = service.insertData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// 响应结果
	return jvo;
}
