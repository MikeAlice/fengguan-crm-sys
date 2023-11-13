#include "stdafx.h"
#include "RemoveCapitalRecordController.h"
#include "service/fincapitalrecord/removecapitalrecord/RemoveCapitalRecordService.h"

Uint64JsonVO::Wrapper RemoveCapitalRecordController::execRemoveCapitalRecords(const List<RemoveCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	// ��Ӧ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��service
	auto items = *dto.get();
	for (auto i = items.begin(); i != items.end(); i++)
	{
		RemoveCapitalRecordDTO::Wrapper item = *i;

		UInt64 ID = item->record_id.getValue(0);
		if (!ID || ID <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

		RemoveCapitalRecordService service;

		if (service.removeData(ID)) {
			jvo->success(ID);
		}
		else
		{
			jvo->fail(ID);
		}
	}
	// ��Ӧ���
	return jvo;
}
