#include "stdafx.h"
#include "ExportCapitalRecordController.h"

#include "service/export_fin_invoice_recefile/ExportCapitalRecordService.h"
//List<ExportCapitalRecordDTO::Wrapper>& dto.//dto�����record_id ����
StringJsonVO::Wrapper ExportCapitalRecordController::execExportCapitalRecord(const List<ExportCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (dto->size() == 0) jvo->init({}, RS_PARAMS_INVALID);

	//����service���󣬽���service�㴦��
	ExportCapitalRecordService service;
	std::string expUrl = service.uploadExportFile(dto);//��controller���record_idͨ��dto����ȥservice
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}

//BooleanJsonVO::Wrapper ExportCapitalRecordController::execDeleteCapitalRecordFile(String filePath, const PayloadDTO& playload)
//{
//	// ����һ��Service
//	ExportCapitalRecordService service;
//	Boolean result = false;
//	if (!filePath->empty()) {
//		// ���ļ��������ϵ��ļ�ɾ��
//		result = service.deleteExportFile(filePath);
//	}
//
//	// ��Ӧ���
//	auto jvo = BooleanJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}
