/*
* 负责人：老菌
*/
#include "stdafx.h"
#include "ExportController.h"

StringJsonVO::Wrapper ExportController::execExportCustomer(ExportCustomerQuery::Wrapper query, const PayloadDTO& playload)
{
	// 定义一个Service
	ExportCustomerService service;
	// 查询数据
	list<ExportCustomerDTO::Wrapper> data = service.listAll(query);
	// 将数据保存为Excel格式并上传到文件服务器
	String result= service.uploadExportFile(data);
	//cout << url << endl;

	// 响应结果
	auto jvo = StringJsonVO::createShared();

	if (result == "upload fail") 
	{
		jvo->init(result, RS_FAIL);
	}
	else 
	{
		jvo->success(result);
	}
	return jvo;
}


