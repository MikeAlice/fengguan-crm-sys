#include "stdafx.h"
#include "QueryBankAccountController.h"
#include "service/fincapitalrecord/querybankaccount/QueryBankAccountService.h"

BankAccountPageJsonVO::Wrapper QueryBankAccountController::execQueryBankAccount(const BankAccountPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个service
	QueryBankAccountService service;
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = BankAccountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
