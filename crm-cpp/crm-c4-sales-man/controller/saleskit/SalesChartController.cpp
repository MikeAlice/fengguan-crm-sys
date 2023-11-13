#include"stdafx.h"
#include"SalesChartController.h"
#include"../../service/saleskit/SalesChartService.h"

SalesChartJsonVO::Wrapper SalesChartController::execQuerySalesChart(const UInt64& date_id) {

	//����һ��Service
	SalesChartService service;
	//��ѯ���
	auto result = service.listRank(date_id);
	// ��Ӧ���
	auto jvo = SalesChartJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

NumberCountingJsonVO::Wrapper SalesChartController::execQueryNumberCounting(const UInt64& date_id) {

	//����һ��Service
	NumberCountingService service;
	//��ѯ���
	auto result = service.listNumberCount(date_id);
	// ��Ӧ���
	auto jvo = NumberCountingJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

