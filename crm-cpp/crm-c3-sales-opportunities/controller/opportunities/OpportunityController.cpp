#include "stdafx.h"
#include "OpportunityController.h"
#include "service/salesopportunity/OpportunityService.h"




//获取销售机名称会列表（用于输入表单下拉列表）长风
GetSalesOppoJsonVO::Wrapper OpportunityController::execQuerySalOppoNameList(const GetSalesOppoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetSalesOppoService service;
	// 查询数据
	auto result = service.getName(query);
	// 响应结果
	auto jvo = GetSalesOppoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


//GetSalesOppoJsonVO::Wrapper OpportunityController::execQuerySalOppoNameList(const UInt32& customer_id)
//{
//	// 定义一个Service
//	GetSalesOppoService service;
//	// 查询数据
//	auto result = service.getName(customer_id);
//	// 响应结果
//	auto jvo = GetSalesOppoJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}



//导出销售机会 归途
StringJsonVO::Wrapper OpportunityController::execQueryExportSalOpp(const OpportunityQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 构建返回对象
	auto jvo = StringJsonVO::createShared();
	// 无需数据校验条件可以为空

	listExportSalOppService  service;
	std::string downloadUrl = service.exportSalOpportunity(query);

	jvo->success(downloadUrl);
	return jvo;

	//return StringJsonVO::createShared();
}
