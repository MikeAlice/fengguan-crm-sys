#include "stdafx.h"
#include "OutboundDetailController.h"
#include "service/outbounddetail/OutboundDetailService.h"


OutboundDetailPageJsonVO::Wrapper OutboundDetailController::execQueryOutboundDetail(const OutboundDetailQuery::Wrapper outboundDetailQuery, const PayloadDTO& payload) {
	//����service
	OutboundDetailService service;
	//����service
	auto result = service.listAll(outboundDetailQuery);
	//��Ӧ���
	auto jvo = OutboundDetailPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}

StringJsonVO::Wrapper OutboundDetailController::execExportOutboundDetails(const List<ExportOutboundDetailsDTO::Wrapper> outboundDetailQuery, const PayloadDTO& payload)
{
	//����service
	OutboundDetailService service;
	//����
	auto result = service.exportData(outboundDetailQuery);
	//��Ӧ
	auto jvo = StringJsonVO::createShared();
	jvo->success(result);

	return jvo;
}
