#include "stdafx.h"
#include "ContractamountController.h"
#include "../../service/contractamount/ContractamountService.h"
#include "../ApiDeclarativeServicesHelper.h"

ContractamountJsonVO::Wrapper ContractamountController::execQueryContractamount(const ContractamountQuery::Wrapper& query,const PayloadDTO& payload)
{
	// ����һ��Service
	ContractamountService service;
	// ��ѯ����
	auto result = service.listAmount(query);
	// ��Ӧ���
	auto jvo = ContractamountJsonVO::createShared();
	jvo->success(result);
	return jvo;
}