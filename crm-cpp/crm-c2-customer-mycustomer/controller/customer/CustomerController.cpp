 #include "stdafx.h"
#include "CustomerController.h"
#include "../../service/addandmodifycustomer/AddAndModifyCustomerService.h"
Uint64JsonVO::Wrapper CustomerController::execAddcustomers(const DetailsCustomerDTO::Wrapper& dto,const PayloadDTO& payload)
{
	// ???Ž?????????
	auto jvo = Uint64JsonVO::createShared();
	// ????§µ??
	// ???§µ??
	if (!dto->source || !dto->name || !dto->grade|| !dto->industry)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ??§¹?§µ??
	if (dto->name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ???????Service
	AddAndModifyCustomerService service;
	// ???????????
	uint64_t id = service.saveData(dto,payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//??????
	return jvo;
}
Uint64JsonVO::Wrapper CustomerController::execModifycustomer(const ModifyCustomerDTO::Wrapper& dto)
{
	// ???Ž?????????
	auto jvo = Uint64JsonVO::createShared();
	// ????§µ??
	if (!dto->customer_id || dto->customer_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ???????Service
	AddAndModifyCustomerService service;
	// ??????????
	if (service.updateData(dto)) {
		jvo->success(dto->customer_id);
	}
	else
	{
		jvo->fail(dto->customer_id);
	}
	// ??????
	return jvo;
}