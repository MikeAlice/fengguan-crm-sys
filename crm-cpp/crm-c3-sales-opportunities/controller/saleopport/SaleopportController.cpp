#include "stdafx.h"
#include "SaleopportController.h"
#include "service/SalesOpportunityList/SalOppListService.h"

SaleopportPageJsonVO::Wrapper SaleopportController::execQuerySalOppList(const SaleopportPageQuery::Wrapper query, const PayloadDTO& payload)
{
	//return SaleopportPageJsonVO::createShared();
	// 定义一个service
	
	querySalOppListService service;
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = SaleopportPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

Uint64JsonVO::Wrapper SaleopportController::execAddInvoices(const AddSaleopportDTO::Wrapper dto, const PayloadDTO& payload)
{
	return Uint64JsonVO::createShared();
}

