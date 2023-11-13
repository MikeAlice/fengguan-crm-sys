#include "stdafx.h"
#include "QueryBankAccountController.h"
#include "service/fincapitalrecord/querybankaccount/QueryBankAccountService.h"

BankAccountPageJsonVO::Wrapper QueryBankAccountController::execQueryBankAccount(const BankAccountPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��service
	QueryBankAccountService service;
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = BankAccountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
