#include "stdafx.h"
#include "SelectAmountInfoController.h"
#include "../../service/paybackmanage/DelPayPlan_GetAmountInfoService.h"


VectorAmountJsonVO::Wrapper SelectAmountInfoController::execSelectAmountInfo(const UInt64& amountid)
{

	// 定义一个Service
	DelPayPlan_GetAmountInfoService service;
	// 查询数据
	int tmp = 1;
	auto result = service.queryOne(amountid, tmp);
	// 响应结果
	auto jvo = VectorAmountJsonVO::createShared();
	if (tmp) {
		result->totalamount = result->totalamount / 1000;
		result->zeroamount = result->zeroamount / 1000;
		result->refundedamount = result->refundedamount / 1000;
		result->invoicedamount = result->invoicedamount / 1000;
	}

	jvo->success(result);

	// 响应结果
	return jvo;
}
