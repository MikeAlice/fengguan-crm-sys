#include "stdafx.h"
#include "ExpendituresController.h"
#include "service/expenditures/ExpendituresService.h"

Uint64JsonVO::Wrapper ExpendituresController::execDeleteInvoices(const List<DelExpendituresDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->size() == 0) jvo->init(UInt64{}, RS_PARAMS_INVALID);

	ExpendituresService service;
	uint64_t delNum = service.removeData(dto);
	if (delNum == 0) jvo->fail(UInt64{});
	else jvo->success(UInt64{ delNum });
	return jvo;
}

StringJsonVO::Wrapper ExpendituresController::execExportInvoices(const List<ExportExpenditures::Wrapper>& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (dto->size() == 0) jvo->init({}, RS_PARAMS_INVALID);

	ExpendituresService service;
	std::string expUrl = service.exportData(dto);
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}

ExpendituresPageJsonVO::Wrapper ExpendituresController::execQueryInvoices(const ExpendituresPageQuery::Wrapper query)
{ExpendituresService service;
	auto result = service.listAll(query);
	auto jvo = ExpendituresPageJsonVO::createShared();
	jvo->success(result);

	return jvo;

}

Uint64JsonVO::Wrapper ExpendituresController::execAddInvoices(const AddExpendituresDTO::Wrapper dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->money) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	if (dto->money < 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	ExpendituresService service;
	uint64_t id = service.addInvoice(dto,stoi(payload.getId()));
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	return jvo;
}
 