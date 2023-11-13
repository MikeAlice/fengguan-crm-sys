#include "stdafx.h"
#include "CollectionRecordsController.h"
#include <ErrorHandler.h>
#include <oatpp-websocket/Handshaker.hpp>
#include <service/collectionrecord/CollectionRecordService.h>
//#include "../../service/collectionrecord/CollectionRecordService.h"

CollectionRecordPageJsonVO::Wrapper CollectionRecordsController::execQueryCollectionRecord(const CollectionRecordQuery::Wrapper& query)
{

    CollectionRecordService service;
    
	auto result = service.listCollectionRecord(query);

	auto jvo = CollectionRecordPageJsonVO::createShared();
    //jvo->success(result);

    return jvo;

}
//
Uint64JsonVO::Wrapper CollectionRecordsController::execAddCollectionRecorde(const CollectionRecordDTO::Wrapper& dto)
{
	 //定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	 //参数校验
	 //非空校验
	if (!dto->record_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	 //有效值校验
	if (dto->money<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	CollectionRecordService service;
	auto id=service.saveCollectrionRecord(dto);
	if (id > 0)
		jvo->success(UInt64(id));
	//else jvo -> fail(UInt64(id));

	return jvo;
}

Uint64JsonVO::Wrapper CollectionRecordsController::execDelCollectionRecord(const DelCollectionRecordDTO::Wrapper& idList)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	for (auto id = idList->record_id->begin(); id != idList->record_id->end(); id++)
		if (*id < 0) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

	CollectionRecordService service;
	// 执行数据删除
	for (auto id = idList->record_id->begin(); id != idList->record_id->end(); id++)
		if (service.removeCollectionRecord(*id)) {
			//jvo->success(*id);
		}
		else
		{
			//jvo->fail(*id);
		}
	return jvo;


	
}



StringJsonVO::Wrapper CollectionRecordsController::execExportCollectionRecord(const DelCollectionRecordDTO::Wrapper& idList)
{
	CollectionRecordService service;
	String fileUrl=service.exportCollectionRecord(idList);
	auto sjvo = StringJsonVO::createShared();

	sjvo->success(fileUrl);
	return sjvo;
  /*  return std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>();*/
}


