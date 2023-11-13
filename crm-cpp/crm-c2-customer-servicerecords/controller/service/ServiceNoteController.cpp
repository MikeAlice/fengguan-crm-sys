#include "stdafx.h"
#include "ServiceNoteController.h"
#include"../crm-c2-customer-servicerecords/service/servicenote/ServiceNoteService.h"

ServiceNotePageJsonVO::Wrapper ServiceNoteController::execQueryServiceNote(const ServiceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ServiceNoteService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ServiceNotePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
