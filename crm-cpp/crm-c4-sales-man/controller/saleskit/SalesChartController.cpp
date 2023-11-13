#include"stdafx.h"
#include"SalesChartController.h"
#include"../../service/saleskit/SalesChartService.h"

SalesChartJsonVO::Wrapper SalesChartController::execQuerySalesChart(const UInt64& date_id) {

	//定义一个Service
	SalesChartService service;
	//查询结果
	auto result = service.listRank(date_id);
	// 响应结果
	auto jvo = SalesChartJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

NumberCountingJsonVO::Wrapper SalesChartController::execQueryNumberCounting(const UInt64& date_id) {

	//定义一个Service
	NumberCountingService service;
	//查询结果
	auto result = service.listNumberCount(date_id);
	// 响应结果
	auto jvo = NumberCountingJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

