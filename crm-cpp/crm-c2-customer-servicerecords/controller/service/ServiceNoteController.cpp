#include "stdafx.h"
#include "ServiceNoteController.h"
#include"../crm-c2-customer-servicerecords/service/servicenote/ServiceNoteService.h"

ServiceNotePageJsonVO::Wrapper ServiceNoteController::execQueryServiceNote(const ServiceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ServiceNoteService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ServiceNotePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
