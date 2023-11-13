#include "stdafx.h"
#include "PayrecordsController.h"
#include "service/payrecords/PayrecordsService.h"

//��ѯ������Ϣ(��ҳ)
PayrecordsPageJsonVO::Wrapper PayrecordsController::execQueryPayrecords(const PayrecordsQuery::Wrapper& query, const PayloadDTO& payload) {
	// ����һ��Service
	PayrecordsService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PayrecordsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}