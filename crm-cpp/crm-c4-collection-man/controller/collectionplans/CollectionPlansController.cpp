#include "stdafx.h"
#include "CollectionPlansController.h"
#include <service/collectionplans/CollectionPlansService.h>

CollectionPlansPageJsonVO::Wrapper CollectionPlansController::execQueryCollection(const CollectionPlansQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CollectionPlansService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CollectionPlansPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper CollectionPlansController::execAddCollectionPlans(const AddCollectionPlanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->customer_id || !dto->name || !dto->contract_name || !dto->backdate || !dto->stages || !dto->money || !dto->contract_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->customer_id < 0 || dto->name->empty() || dto->contract_name->empty() || dto->backdate->empty() || dto->stages <= 0 || dto->money < 0 || dto->contract_id < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ȡ��ǰ�û���Ϣ
	Int32 create_user_id = atoi(payload.getId().c_str());
	// ����һ��Service
	CollectionPlansService service;
	// ִ����������
	uint64_t id = service.saveData(dto, create_user_id);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
