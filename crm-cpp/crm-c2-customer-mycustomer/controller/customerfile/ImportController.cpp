/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#include "ImportController.h"
#include "service/customerfile/ImportCustomerService.h"


StringJsonVO::Wrapper ImportController::execUploadCustomerFileOne(std::shared_ptr<IncomingRequest> request)
{
	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();

	// ����һ��Service
	ImportCustomerService service;
	// �������ļ����浽ҵ�����������
	String result = service.uploadImportFile(request);
	if (result.getValue("") == "format error")
	{
		jvo->init(result, RS_PARAMS_INVALID);
		//jvo->fail(result);
	}
	else
	{
		jvo->success(result);
	}
	return jvo;
}

ImportResultJsonVO::Wrapper ImportController::execImportCustomer(String fileName, const PayloadDTO& playload)
{
	// ����һ��Service
	ImportCustomerService service;

	// ��Ӧ���
	auto jvo = ImportResultJsonVO::createShared();
	if (fileName->size() != 15) 
	{
		jvo->init(ImportResultDTO::Wrapper(), RS_PARAMS_INVALID);
		//jvo->fail(ImportResultDTO::Wrapper());
	}
	else 
	{
		// �������ļ����浽ҵ�����������
		ImportResultDTO::Wrapper result = service.importCustomer(fileName);
		jvo->success(result);
	}
	return jvo;
}
