/*
* 负责人：老菌
*/
#include "stdafx.h"
#include "ImportController.h"
#include "service/customerfile/ImportCustomerService.h"


StringJsonVO::Wrapper ImportController::execUploadCustomerFileOne(std::shared_ptr<IncomingRequest> request)
{
	// 响应结果
	auto jvo = StringJsonVO::createShared();

	// 定义一个Service
	ImportCustomerService service;
	// 将导入文件保存到业务服务器本地
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
	// 定义一个Service
	ImportCustomerService service;

	// 响应结果
	auto jvo = ImportResultJsonVO::createShared();
	if (fileName->size() != 15) 
	{
		jvo->init(ImportResultDTO::Wrapper(), RS_PARAMS_INVALID);
		//jvo->fail(ImportResultDTO::Wrapper());
	}
	else 
	{
		// 将导入文件保存到业务服务器本地
		ImportResultDTO::Wrapper result = service.importCustomer(fileName);
		jvo->success(result);
	}
	return jvo;
}
