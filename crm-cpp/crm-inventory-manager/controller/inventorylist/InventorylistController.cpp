#include "stdafx.h"
#include "InventorylistController.h"
#include "service/inventorylist/InventoryListService.h"

InventoryListPageJsonVO::Wrapper InventoryListController::execQueryInventoryList(const InventoryListPageQuery::Wrapper& storagedetailsQuery, const PayloadDTO& payload)
{
	// ����һ��Service
	InventoryListService service;
	// ��ѯ����
	auto result = service.listAll(storagedetailsQuery);
	// ��Ӧ���
	auto jvo = InventoryListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper InventoryListController::execExportInventoryList(const List<ExportInventoryList::Wrapper>& storagedetailsQuery, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (storagedetailsQuery->size() == 0) jvo->init({}, RS_PARAMS_INVALID);

	InventoryListService service;
	std::string expUrl = service.exportData(storagedetailsQuery);
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}
