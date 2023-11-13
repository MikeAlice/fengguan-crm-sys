#include "stdafx.h"
#include "InStorageController.h"
#include "../../service/in_storage/InStorageService.h"
#include "../ApiDeclarativeServicesHelper.h"

InStoragePageJsonVO::Wrapper InStorageController::execQueryInStorage(const InStorageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	InStorageService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InStoragePageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}

Uint64JsonVO::Wrapper InStorageController::execAddInStorage(const InStorageBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验 : intro可以为空，其他不可
	if (!dto->contract_id || !dto->title || !dto->number || !dto->store_id || !dto->into_type || !dto->money)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验 : 合同编号，入库金额不能小于0
	if (dto->contract_id < 0 || dto->title->empty() || dto->number < 0 || dto->store_id < 0 || dto->into_type->empty() || dto->money < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	InStorageService service;

	// 定义在service和dao层传输的dto
	auto sub = AddInStorageDTO::createShared();
	INSTORAGEBASEDTO_TO_ADDINSTORAGEDTO(dto, sub);

	// 从payload中获取id并将其从string转为UInt64
	sub->create_user_id = std::stoi(payload.getId());
	if (!dto->intro) sub->intro = "";

	// 执行数据新增
	uint64_t id = service.saveData(sub);
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

InStorageJsonVO::Wrapper InStorageController::execQueryInStorageDetails(const UInt64& id)
{
	// 定义一个Service
	InStorageService service;
	auto jvo = InStorageJsonVO::createShared();
	auto result = InStorageDTO::createShared();

	if (id && id > 0)
		result = service.listOne(id), jvo->success(result);
	else jvo->fail(result), jvo->message = "ID invalid.";

	return jvo;
}