#include "stdafx.h"
#include "BankAccountController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/bankaccount/BankAccountDO.h"
#include "service/bankaccount/BankAccountService.h"
#include "tree/TreeUtil.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
//分页查询
BankAccountPageJsonVO::Wrapper BankAccountController::execQueryBankAccount(const BankAccountQuery::Wrapper& query, const PayloadDTO& payload)
{
	
	// 定义一个Service
	BankAccountService service;
	auto result = service.listAll(query);
	 //响应结果
	auto jvo = BankAccountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
BankAccountListJsonVO::Wrapper BankAccountController::execGetBankAccountList(const BankAccountListQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 定义一个Service
	BankAccountService service;
	auto result = service.getlistAll(query);
	//响应结果
	auto jvo = BankAccountListJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
// 3.3 演示新增数据
Uint64JsonVO::Wrapper BankAccountController::execAddBankAccount(const BankAccountDTO::Wrapper& dto)
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
	BankAccountService service;
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
Uint64JsonVO::Wrapper  BankAccountController::execModifyBankAccount(const BankAccountDTO::Wrapper& dto)
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
	BankAccountService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->bank_id);
	}
	else
	{
		jvo->fail(dto->bank_id);
	}
	// 响应结果
	return jvo;
}
// 3.3 演示删除数据
Uint64JsonVO::Wrapper  BankAccountController::execRemoveBankAccount(const UInt64&bank_id)
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
	BankAccountService service;
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
StringJsonVO::Wrapper BankAccountController::execExportBankAccount(const List<BankAccountExportDTO::Wrapper>& query, const PayloadDTO& payload)
{
	// 定义一个Service
	BankAccountService service;
	std::string url = service.exportData(query);
	auto jvo = StringJsonVO::createShared();
	if (query->size() == 0)
		jvo->init({}, RS_PARAMS_INVALID);
	if (url == "")
		jvo->fail({});
	else
		jvo->success(url);
	return jvo;
}
