#include "stdafx.h"
#include "UpdatePayPlanController.h"
#include "../../service/update-pay-plan/UpdatePayPlanService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper UpdatePayPlanController::execupdatePayPlan(const UpdatePayPlanDTO::Wrapper& dto) {
	/*auto result = StringJsonVO::createShared();
	result->success(String("add pay record !"));
	return result;*/
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->contract_name ||  !dto->supplier_name || !dto->money || !dto->stages)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (stof(dto->money) < 0.0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	UpdatePayPlanService service;
	// ִ����������
	uint64_t id = service.dealWithResult(dto);
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