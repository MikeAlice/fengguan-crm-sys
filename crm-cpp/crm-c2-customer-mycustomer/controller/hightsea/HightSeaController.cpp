//ʱ�䣺2023��10��19��
//���ߣ���Ƥ�����
//���ݣ�Ͷ�빫���ӿ�
#include "stdafx.h"
#include "HightSeaController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/basecustormer/BaseCustormerService.h"

Uint64JsonVO::Wrapper HightSeaController::execInvestHightSea(const List<UInt64> idArray)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	auto& id = *idArray.get();

	for (auto i = id.begin(); i != id.end(); i++)
	{
		UInt64 ID = *i;
		//���ID�Ƿ�Ϸ�
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
