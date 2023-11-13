#include"stdafx.h"
#include"GetCustomerController.h"

GetCustomerPageJsonVO::Wrapper GetCustomerController::execGetCustomer(const GetCustomerQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetCustomerService service;
	// 查询数据
	auto result = service.getCustomer(query);
	// 响应结果
	auto jvo = GetCustomerPageJsonVO::createShared();
	if (result->rows->size() != 0) {	
		jvo->success(result);
		jvo->message = u8"查询结果不为空";
	}
	else {
		jvo->fail(result);
		jvo->message = u8"查询结果为空";
	}
	return jvo;
}
