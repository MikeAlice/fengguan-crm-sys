#include "stdafx.h"
#include "QueryCapitalRecordController.h"
#include "service/fincapitalrecord/querycapitalrecord/QueryCapitalRecordService.h"

// ��ȡ�����б���ҳ+������ �����ˣ�����
CapitalRecordPageJsonVO::Wrapper QueryCapitalRecordController::execQueryCapitalRecord(const CapitalRecordPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��service
	QueryCapitalRecordService service;
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CapitalRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}