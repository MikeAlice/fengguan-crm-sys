#include "stdafx.h"
#include "FeeIncomeController.h"
#include "../../service/feeincome/FeeIncomeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "tree/TreeUtil.h"
FeeIncomeTreeJsonVO::Wrapper FeeIncomeController::execQueryALLFeeIncome(const PayloadDTO& payload)
{
	 //定义一个Service
	 FeeIncomeService service;
	 auto default_query = FeeIncomeQuery::Wrapper::createShared();
	 default_query->parentid = 0;
	 default_query->depth = 100;
	// 查询数据
	auto result = service.listTree(default_query);
	// 响应结果

	return result;
}

FeeIncomeTreeJsonVO::Wrapper FeeIncomeController::execQueryALLFeeIncomeTree(FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload)
{
	 //定义一个Service
	FeeIncomeService service;
	// 查询数据
	auto result = service.listTree(query);
	// 响应结果
	
	return result;
}
// 获取类型列表(分页 + 条件)
FeeIncomePageJsonVO::Wrapper FeeIncomeController::execQueryType(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	FeeIncomeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FeeIncomePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//FeeIncomePageJsonVO::Wrapper FeeIncomeController::execQueryFeeIncome(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload)
//{
//
//	// 定义一个Service
//	FeeIncomeService service;
//	auto result = service.listAll(query);
//	//响应结果
//	auto jvo = FeeIncomePageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//
//}
// 3.3 演示新增数据
Uint64JsonVO::Wrapper FeeIncomeController::execAddFeeIncome(const FeeIncomeDTO::Wrapper& dto)
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
	FeeIncomeService service;
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
Uint64JsonVO::Wrapper  FeeIncomeController::execModifyFeeIncome(const FeeIncomeDTO::Wrapper& dto)
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
	FeeIncomeService service;
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
// 3.3 演示删除数据
Uint64JsonVO::Wrapper  FeeIncomeController::execRemoveFeeIncome(const UInt64& bank_id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	/*if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// 定义一个Service
	FeeIncomeService service;
	// 执行数据删除
	if (service.removeData(bank_id.getValue(0))) {
		jvo->success(bank_id);
	}
	else
	{
		jvo->fail(bank_id);
	}
	// 响应结果
	return jvo;
}