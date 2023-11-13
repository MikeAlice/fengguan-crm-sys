//时间：2023年10月19日
//作者：狗皮电耗子
//内容：投入公海接口
#include "stdafx.h"
#include "HightSeaController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/basecustormer/BaseCustormerService.h"

Uint64JsonVO::Wrapper HightSeaController::execInvestHightSea(const List<UInt64> idArray)
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

		if (service.hightSeaCustormer(ID)) {
			jvo->success(ID);
		}
		else
		{
			jvo->fail(ID);
		}
	}

	return jvo;
}
