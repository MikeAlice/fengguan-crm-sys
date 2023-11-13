#include "stdafx.h"
#include "FinpayrecordController.h"
#include "service/finpayrecord/FinpayrecordService.h"

Uint64JsonVO::Wrapper FinpayrecordController::execRemoveFinpayrecord(const List<DelFinpayrecordDTO::Wrapper>& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->size() == 0) jvo->init(UInt64{}, RS_PARAMS_INVALID);

	FinpayrecordService service;
	uint64_t delNum = service.removeData(dto);
	if (delNum == 0) jvo->fail(UInt64{});
	else jvo->success(UInt64{ delNum });
	return jvo;
}
