//2023��10��19��
//���ߣ���Ƥ�����
//���ݣ�ɾ���ͻ�
#include "stdafx.h"
#include "DeleteCustormerController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/basecustormer/BaseCustormerService.h"

Uint64JsonVO::Wrapper DeleteCustormerController::execRemoveCustormer(const List<UInt64> idArray)
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