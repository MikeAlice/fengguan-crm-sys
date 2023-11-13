#include "stdafx.h"
#include "ConfirmRemovePayController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/confirm_remove_pay/ConfirmRemovePayService.h"

Uint64JsonVO::Wrapper ConfirmRemovePayController::execRemoveConfirmpay(oatpp::List<UInt64> plan_ids) {
	auto jvo = Uint64JsonVO::createShared();
	int count = 0;
	if (plan_ids->empty()) {
		jvo->setStatus(ResultStatus(u8"����Ϊ�գ��봫�������", 9999));
		return jvo;
	}
	int n = plan_ids->size();
	// ����һ��Service
	ConfirmRemovePayService service;
	int i;
	for (i = 0; i < n; i++) {
		// ����У��
		if (!service.removeData(plan_ids[i])) {
			count++;
		}
	}
	if (count == n) {
		jvo->fail(plan_ids[0]);
	}
	else {
		jvo->success(plan_ids[0]);
	}
	//���ؽ��
	return jvo;

}

Uint64JsonVO::Wrapper ConfirmRemovePayController::execModifyConfirmpay(const UInt64& id) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ConfirmRemovePayService service;
	// ִ�������޸�
	if (service.updateData(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}
//
