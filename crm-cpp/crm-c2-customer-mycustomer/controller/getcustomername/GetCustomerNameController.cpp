#include"stdafx.h"
#include"GetCustomerNameController.h"

GetCustomerNameJsonVO::Wrapper GetCustomerNameController::execGetCustomerName(const GetCustomerNameQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetCustomerNameService service;
	// 查询数据
	auto result = service.getName(query);
	// 响应结果
	return result;
}