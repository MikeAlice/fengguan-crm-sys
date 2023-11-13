#include "stdafx.h"
#include "FlowrecordController.h"
#include "service/flowrecord/FlowrecordService.h"

FlowrecordPageJsonVO::Wrapper FlowrecordController::execQueryFlowrecord(const FlowrecordPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	FlowrecordService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FlowrecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FlowrecordController::execExportFlowrecord(const List<FlowrecordExportDTO::Wrapper>& query, const PayloadDTO& payload)
{
	// 定义一个Service
	FlowrecordService service;
	std::string url = service.exportData(query);
	auto jvo = StringJsonVO::createShared();
	if (query->size() == 0)
		jvo->init({}, RS_PARAMS_INVALID);
	if (url == "")
		jvo->fail({});
	else
		jvo->success(url);
	return jvo;
}
