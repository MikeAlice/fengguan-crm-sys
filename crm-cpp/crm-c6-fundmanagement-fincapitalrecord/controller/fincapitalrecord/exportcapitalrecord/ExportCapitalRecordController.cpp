#include "stdafx.h"
#include "ExportCapitalRecordController.h"
#include "service/fincapitalrecord/exportcapitalrecord/ExportCapitalRecordService.h"

// 导出数据 负责人：超能
StringJsonVO::Wrapper ExportCapitalRecordController::execExportCapitalRecord(const List<ExportCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (dto->size() == 0) jvo->init({}, RS_PARAMS_INVALID);
	ExportCapitalRecordService service;
	std::string expUrl = service.exportData(dto);
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}
