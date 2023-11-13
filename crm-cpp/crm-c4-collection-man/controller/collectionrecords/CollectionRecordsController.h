#pragma once

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/collectionrecord/CollectionRecordQuery.h"
#include "domain/dto/collectionrecords/CollectionRecordDTO.h"
#include "domain/vo/collectionrecorde/CollectionRecordVO.h"
#include "../crm-c4-collection-man/domain/dto/collectionrecords/delCollectionRecordDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

class CollectionRecordsController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(CollectionRecordsController);

public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryCollectionRecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("collectionRecord.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CollectionRecordPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "customer_name", ZH_WORDS_GETTER("collectionRecord.field.customer_name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("collectionRecord.field.start_time"), "2010-10-10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("collectionRecord.field.end_time"), "2010-10-30", false);


	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/collection-man/collectionRecord/qurery", queryCollectionRecord, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, CollectionRecordQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCollectionRecord(userQuery));// , authObject->getPayload()));

	}

	 //3.1 定义新增接口描述
	ENDPOINT_INFO(addCollectionRecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("collectionRecord.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/collection-man/collectionRecord/add", addCollectionRecord, BODY_DTO(CollectionRecordDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		return createDtoResponse(Status::CODE_200, execAddCollectionRecorde(dto));
	}

	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("collectionRecord.delete.summary"), delCollectionRecord, Uint64JsonVO::Wrapper);

	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT(API_M_DEL, "/collection-man/collectionRecord/delete", delCollectionRecord, BODY_DTO(DelCollectionRecordDTO::Wrapper, dto), execDelCollectionRecord(dto));
	
	/* 定义一个文件导出接口
	 定义描述*/
	ENDPOINT_INFO(exportCollectionRecord) {
		info->summary = ZH_WORDS_GETTER("collectionRecord.export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义端点
	ENDPOINT(API_M_POST, "/collection-man/collectionRecord/export", exportCollectionRecord, BODY_DTO(DelCollectionRecordDTO::Wrapper, idList)) {
		return createDtoResponse(Status::CODE_200, execExportCollectionRecord(idList));
	}
	

private:
	CollectionRecordPageJsonVO::Wrapper execQueryCollectionRecord(const CollectionRecordQuery::Wrapper& queery);// , const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execAddCollectionRecorde(const CollectionRecordDTO::Wrapper& dto);

	Uint64JsonVO::Wrapper execDelCollectionRecord(const DelCollectionRecordDTO::Wrapper& id);

	StringJsonVO::Wrapper execExportCollectionRecord(const DelCollectionRecordDTO::Wrapper&idList);

};


#include OATPP_CODEGEN_END(ApiController)
