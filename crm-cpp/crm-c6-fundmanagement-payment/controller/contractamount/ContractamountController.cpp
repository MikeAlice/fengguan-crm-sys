#include "stdafx.h"
#include "ContractamountController.h"
#include "../../service/contractamount/ContractamountService.h"
#include "../ApiDeclarativeServicesHelper.h"

ContractamountJsonVO::Wrapper ContractamountController::execQueryContractamount(const ContractamountQuery::Wrapper& query,const PayloadDTO& payload)
{
	// 定义一个Service
	ContractamountService service;
	// 查询数据
	auto result = service.listAmount(query);
	// 响应结果
	auto jvo = ContractamountJsonVO::createShared();
	jvo->success(result);
	return jvo;
}