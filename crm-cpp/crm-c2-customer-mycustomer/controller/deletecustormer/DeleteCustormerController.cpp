//2023年10月19日
//作者：狗皮电耗子
//内容：删除客户
#include "stdafx.h"
#include "DeleteCustormerController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/basecustormer/BaseCustormerService.h"

Uint64JsonVO::Wrapper DeleteCustormerController::execRemoveCustormer(const List<UInt64> idArray)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

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

		BaseCustormerService service;

		if (service.delecteCustormer(ID)) {
			jvo->success(ID);
		}
		else
		{
			jvo->fail(ID);
		}
	}
	
	return jvo;
}