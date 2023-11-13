#include "stdafx.h"
#include "QueryCapitalRecordController.h"
#include "service/fincapitalrecord/querycapitalrecord/QueryCapitalRecordService.h"

// 获取数据列表（分页+条件） 负责人：超能
CapitalRecordPageJsonVO::Wrapper QueryCapitalRecordController::execQueryCapitalRecord(const CapitalRecordPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个service
	QueryCapitalRecordService service;
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CapitalRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}