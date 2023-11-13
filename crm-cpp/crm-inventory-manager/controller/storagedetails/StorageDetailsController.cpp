#include "stdafx.h"
#include "StorageDetailsController.h"
#include "service/storagedetails/StorageDetailsService.h"

StorageDetailsPageJsonVO::Wrapper StorageDetailsController::execQueryStorageDetails(const StorageDetailsQuery::Wrapper storagedetailsQuery, const PayloadDTO& payload)
{
	// 定义一个Service
	StorageDetailsService service;
	// 查询数据
	auto result = service.listAll(storagedetailsQuery);
	// 响应结果
	auto jvo = StorageDetailsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper StorageDetailsController::execExportStorageDetails(const List<ExportStorageDetailsDTO::Wrapper> storagedetailsQuery, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (storagedetailsQuery->size() == 0) jvo->init({}, RS_PARAMS_INVALID);

	StorageDetailsService service;
	std::string expUrl = service.exportData(storagedetailsQuery);
	if (expUrl == "") jvo->fail({});
	else jvo->success(expUrl);
	return jvo;
}
