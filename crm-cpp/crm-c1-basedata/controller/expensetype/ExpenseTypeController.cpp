#include "stdafx.h"
#include "ExpenseTypeController.h"
#include <service/expensetype/ExpenseTypeService.h>

//ExpenseTypePageJsonVO::Wrapper ExpenseTypeController::execQueryExpenseType(const ExpenseTypeQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	return ExpenseTypePageJsonVO::createShared();
//}
ExpenseTypePageJsonVO::Wrapper ExpenseTypeController::execQueryExpenseType(const ExpenseTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ExpenseTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ExpenseTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


// 3.3 演示新增数据
Uint64JsonVO::Wrapper ExpenseTypeController::execAddExpenseType(const ExpenseTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//// 非空校验
	//if (!dto->card || !dto->name || !dto->holders ||!dto->address||!dto->sort)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (dto->card < 0 || dto->name->empty() || dto->address->empty()|| dto->holders->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	// 定义一个Service
	ExpenseTypeService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
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
// 3.3 演示修改数据
Uint64JsonVO::Wrapper  ExpenseTypeController::execModifyExpenseType(const ExpenseTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->bank_id || dto->bank_id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 定义一个Service
	ExpenseTypeService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper ExpenseTypeController::execRemoveType(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ExpenseTypeService service;
	// 执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
ExpenseTreeJsonVO::Wrapper ExpenseTypeController::execQueryALLExpenseTree(const PayloadDTO& payload)
{
	//定义一个Service
	ExpenseService service;
	auto default_query = ExpenseQuery::Wrapper::createShared();
	default_query->parentid = 0;
	default_query->depth = 100;
	// 查询数据
	auto result = service.listTree(default_query);
	// 响应结果

	return result;
}

ExpenseTreeJsonVO::Wrapper ExpenseTypeController::execQueryExpenseTree(ExpenseQuery::Wrapper& query, const PayloadDTO& payload)
{
	//定义一个Service
	ExpenseService service;
	// 查询数据
	auto result = service.listTree(query);
	// 响应结果

	return result;
}