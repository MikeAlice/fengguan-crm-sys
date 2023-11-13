#include "stdafx.h"
#include "Other_income_statementController.h"
#include "service/other_income_statement/Other_income_statementService.h"

Uint64JsonVO::Wrapper Other_income_statementController::execDelInvoices(const List<DelOisDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->size() == 0) jvo->init(UInt64{}, RS_PARAMS_INVALID);

	Other_income_statementService service;
	uint64_t delNum = service.removeData(dto);
	if (delNum == 0) jvo->fail(UInt64{});
	else jvo->success(UInt64{ delNum });
	return jvo;
}

StringJsonVO::Wrapper Other_income_statementController::execExportdata(const List<ExpOisDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (dto->size() == 0) jvo->init({}, RS_PARAMS_INVALID);

	Other_income_statementService service;
	std::string expUrl = service.exporttData(dto);
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}
