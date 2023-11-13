#include "stdafx.h"
#include "PayrecordsController.h"
#include "service/payrecords/PayrecordsService.h"

//查询付款信息(分页)
PayrecordsPageJsonVO::Wrapper PayrecordsController::execQueryPayrecords(const PayrecordsQuery::Wrapper& query, const PayloadDTO& payload) {
	// 定义一个Service
	PayrecordsService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PayrecordsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}