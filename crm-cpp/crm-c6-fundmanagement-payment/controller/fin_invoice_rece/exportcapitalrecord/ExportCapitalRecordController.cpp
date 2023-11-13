#include "stdafx.h"
#include "ExportCapitalRecordController.h"

#include "service/export_fin_invoice_recefile/ExportCapitalRecordService.h"
//List<ExportCapitalRecordDTO::Wrapper>& dto.//dto里面放record_id 单号
StringJsonVO::Wrapper ExportCapitalRecordController::execExportCapitalRecord(const List<ExportCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (dto->size() == 0) jvo->init({}, RS_PARAMS_INVALID);

	//创建service对象，进行service层处理
	ExportCapitalRecordService service;
	std::string expUrl = service.uploadExportFile(dto);//在controller层吧record_id通过dto传进去service
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}

//BooleanJsonVO::Wrapper ExportCapitalRecordController::execDeleteCapitalRecordFile(String filePath, const PayloadDTO& playload)
//{
//	// 定义一个Service
//	ExportCapitalRecordService service;
//	Boolean result = false;
//	if (!filePath->empty()) {
//		// 将文件服务器上的文件删除
//		result = service.deleteExportFile(filePath);
//	}
//
//	// 响应结果
//	auto jvo = BooleanJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}
