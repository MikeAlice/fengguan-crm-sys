#include "stdafx.h"
#include "ExportServicenoteController.h"

StringJsonVO::Wrapper ExportServicenoteController::execExportServiceNote(ExportServiceNoteQuery::Wrapper query, const PayloadDTO& payload)
{
	// 定义一个Service
	ExportServiceNoteService service;
	// 查询数据
	list<ServiceDetailDTO::Wrapper> result = service.listAll(query);
	// 将数据保存为Excel格式并上传到文件服务器
	String url = service.uploadExportFile(result);
	//cout << url << endl;

	// 响应结果
	auto jvo = StringJsonVO::createShared();
	jvo->success(url);
	return jvo;
}


