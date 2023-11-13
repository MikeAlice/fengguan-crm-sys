#include "stdafx.h"
#include "OutboundDetailController.h"
#include "service/outbounddetail/OutboundDetailService.h"


OutboundDetailPageJsonVO::Wrapper OutboundDetailController::execQueryOutboundDetail(const OutboundDetailQuery::Wrapper outboundDetailQuery, const PayloadDTO& payload) {
	//定义service
	OutboundDetailService service;
	//调用service
	auto result = service.listAll(outboundDetailQuery);
	//响应结果
	auto jvo = OutboundDetailPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}

StringJsonVO::Wrapper OutboundDetailController::execExportOutboundDetails(const List<ExportOutboundDetailsDTO::Wrapper> outboundDetailQuery, const PayloadDTO& payload)
{
	//定义service
	OutboundDetailService service;
	//调用
	auto result = service.exportData(outboundDetailQuery);
	//响应
	auto jvo = StringJsonVO::createShared();
	jvo->success(result);

	return jvo;
}
