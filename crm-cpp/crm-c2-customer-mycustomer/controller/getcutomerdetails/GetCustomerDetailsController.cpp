#include"stdafx.h"
#include "controller/getcutomerdetails/GetCustomerDetailsController.h"

GetCustomerDetailsJsonVO::Wrapper GetCustomerDetailsController::execQueryCustomerDetails(GetCustomerDetailsQuery::Wrapper query, const PayloadDTO& playload)
{
	// 定义一个Service
	GetCustomerDetailsService service;
	// 查询数据
	auto result = service.getCustomerDetails(query);
	// 响应结果
	auto jvo = GetCustomerDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
