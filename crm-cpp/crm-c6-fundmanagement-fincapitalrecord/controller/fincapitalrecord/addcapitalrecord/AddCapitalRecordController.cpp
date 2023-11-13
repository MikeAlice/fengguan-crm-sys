#include "stdafx.h"
#include "AddCapitalRecordController.h"
#include "service/fincapitalrecord/addcapitalrecord/AddCapitalRecordService.h"

// �������
StringJsonVO::Wrapper AddCapitalRecordController::execAddCapitalRecord(const AddCapitalRecordDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->type_id != 1 && dto->type_id != -1)
	{
		jvo->init(u8"type_id����Ϊ1��-1", RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->money) {
		jvo->init(u8"����Ϊ��", RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->money <= 0) {
		jvo->init(u8"����С��0", RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��service
	AddCapitalRecordService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(u8"��ӳɹ�");
	}
	else
	{
		jvo->fail(u8"���ʧ��");
	}
	//��Ӧ���
	return jvo;
}