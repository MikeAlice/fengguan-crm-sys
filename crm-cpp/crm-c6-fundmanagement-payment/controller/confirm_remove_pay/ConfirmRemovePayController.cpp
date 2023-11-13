#include "stdafx.h"
#include "ConfirmRemovePayController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/confirm_remove_pay/ConfirmRemovePayService.h"

Uint64JsonVO::Wrapper ConfirmRemovePayController::execRemoveConfirmpay(oatpp::List<UInt64> plan_ids) {
	auto jvo = Uint64JsonVO::createShared();
	int count = 0;
	if (plan_ids->empty()) {
		jvo->setStatus(ResultStatus(u8"参数为空，请传入参数！", 9999));
		return jvo;
	}
	int n = plan_ids->size();
	// 定义一个Service
	ConfirmRemovePayService service;
	int i;
	for (i = 0; i < n; i++) {
		// 参数校验
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
	//返回结果
	return jvo;

}

Uint64JsonVO::Wrapper ConfirmRemovePayController::execModifyConfirmpay(const UInt64& id) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ConfirmRemovePayService service;
	// 执行数据修改
	if (service.updateData(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
//
