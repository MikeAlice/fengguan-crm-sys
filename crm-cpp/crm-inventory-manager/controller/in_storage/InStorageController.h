#pragma once
#ifndef INSTORAGECONTROLLER_H__
#define INSTORAGECONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "domain/vo/in_storage/InStorageJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * InStorage控制器：
 * 负责人：CC
 */
class InStorageController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InStorageController);
	// 3 定义接口
public:

	// 获取入库单列表（分页+条件）负责人：CC
	ENDPOINT_INFO(queryInStorage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("instorage.controller.get.query-instorage"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InStoragePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "title", ZH_WORDS_GETTER("instorage.field.title"), "default", false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "store_id", ZH_WORDS_GETTER("instorage.field.store_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "status", ZH_WORDS_GETTER("instorage.field.status"), 1, false);
	}
	ENDPOINT(API_M_GET, "/inventory-manager/query-instorage", queryInStorage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, InStorageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInStorage(userQuery, authObject->getPayload()));
	}

	// 查询入库明细  负责人：CC
	ENDPOINT_INFO(queryInStorageDetails) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("instorage.controller.get.query-instorage_details"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InStorageJsonVO);
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("instorage.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/inventory-manager/query-instorage_details/{id}", queryInStorageDetails, PATH(UInt64, id), execQueryInStorageDetails(id));


	// 添加入库单  负责人：CC
	ENDPOINT_INFO(addInStorage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("instorage.controller.post.add-instorage"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/inventory-manager/add-instorage", addInStorage, BODY_DTO(InStorageBaseDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddInStorage(dto, authObject->getPayload()));
	}

private:
	InStoragePageJsonVO::Wrapper execQueryInStorage(const InStorageQuery::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddInStorage(const InStorageBaseDTO::Wrapper& dto, const PayloadDTO& payload);
	InStorageJsonVO::Wrapper execQueryInStorageDetails(const UInt64& id);

};



// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // INSTORAGECONTROLLER_H__