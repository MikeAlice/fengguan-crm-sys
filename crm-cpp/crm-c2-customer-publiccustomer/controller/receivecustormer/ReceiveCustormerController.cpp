#include "stdafx.h"
#include "ReceiveCustormerController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/publiccustormer/InverseCustormerService.h"

Uint64JsonVO::Wrapper ReceiveCustormerController::execReceiveCustormer(const List<UInt64>& idArray, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	UInt64 linkmanID = stoi(payload.getId());
	auto& id = *idArray.get();

	for (auto i = id.begin(); i != id.end(); i++)
	{
		UInt64 ID = *i;
		//检查ID是否合法
		if (!ID || ID <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		InverseCustormerService service;
		if (service.inverseCustormer(ID, linkmanID)) {
			jvo->success(ID);
		}
		else {
			jvo->fail(ID);
		}
	}

	return jvo;
}
