#include "stdafx.h"
#include "InStorageController.h"
#include "../../service/in_storage/InStorageService.h"
#include "../ApiDeclarativeServicesHelper.h"

InStoragePageJsonVO::Wrapper InStorageController::execQueryInStorage(const InStorageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	InStorageService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InStoragePageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}

Uint64JsonVO::Wrapper InStorageController::execAddInStorage(const InStorageBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У�� : intro����Ϊ�գ���������
	if (!dto->contract_id || !dto->title || !dto->number || !dto->store_id || !dto->into_type || !dto->money)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ�� : ��ͬ��ţ�������С��0
	if (dto->contract_id < 0 || dto->title->empty() || dto->number < 0 || dto->store_id < 0 || dto->into_type->empty() || dto->money < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	InStorageService service;

	// ������service��dao�㴫���dto
	auto sub = AddInStorageDTO::createShared();
	INSTORAGEBASEDTO_TO_ADDINSTORAGEDTO(dto, sub);

	// ��payload�л�ȡid�������stringתΪUInt64
	sub->create_user_id = std::stoi(payload.getId());
	if (!dto->intro) sub->intro = "";

	// ִ����������
	uint64_t id = service.saveData(sub);
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

InStorageJsonVO::Wrapper InStorageController::execQueryInStorageDetails(const UInt64& id)
{
	// ����һ��Service
	InStorageService service;
	auto jvo = InStorageJsonVO::createShared();
	auto result = InStorageDTO::createShared();

	if (id && id > 0)
		result = service.listOne(id), jvo->success(result);
	else jvo->fail(result), jvo->message = "ID invalid.";

	return jvo;
}