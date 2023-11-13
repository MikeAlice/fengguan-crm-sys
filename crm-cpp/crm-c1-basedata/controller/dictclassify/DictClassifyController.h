#pragma once
#ifndef _DICTCLASSIFY_CONTROLLER_
#define _DICTCLASSIFY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/dictclassify/DictClassifyQuery.h"
#include "domain/dto/dictclassify/DictClassifyDTO.h"
#include "domain/vo/dictclassify/DictClassifyVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
	字典分类 新增和修改功能
*/

class DictClassifyController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DictClassifyController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querydictclassify) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictclassify.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DictClassifyPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "typeName", ZH_WORDS_GETTER("dictclassify.field.typename"), "typeName", false);
		
	}
	ENDPOINT(API_M_GET, "data-dictionary/dictclassify/query-dictclassify", querydictclassify, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DictClassifyQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDictClassify(userQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addDictClassify) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictclassify.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "data-dictionary/dictclassify/add-dictclassify", addDictClassify, BODY_DTO(DictClassifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDictClassify(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictclassify.put.summary"), modifyDictClassify, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "data-dictionary/dictclassify/modify-dictclassify", modifyDictClassify, BODY_DTO(DictClassifyDTO::Wrapper, dto), execModifyDictClassify(dto));
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeDictClassify) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictclassify.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("dictClassify.field.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "data-dictionary/dictclassify/delete-dictclassify/{id}", removeDictClassify, PATH(UInt64, id), execRemoveDictClassify(id));
	


	//// 3.1 定义批量删除接口描述
	//ENDPOINT_INFO(removeMoreDictClassify) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictclassify.delete.summary"), Uint64JsonVO::Wrapper);
	//	//// 定义其他路径参数说明
	//	//API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("dictClassify.field.id"), 1, true);
	//}
	//// 3.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/dictclassify/delete-dictclassify/{id}", removeMoreDictClassify, BODY_DTO(DictClassifyDTO::Wrapper, dto), execRemoveMoreDictClassify(dto));

	//
	// 3.1 定义获取下拉列表
	ENDPOINT_INFO(getdictclassifylist) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictclassify.getlist.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DictClassifyListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "typeName", ZH_WORDS_GETTER("dictclassify.field.typename"), "typeName", false);
	

	}
	ENDPOINT(API_M_GET, "data-dictionary/dictclassify/get-dictclassifylist", getdictclassifylist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DictClassifyListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetDictClassifyList(userQuery, authObject->getPayload()));
	}


private:
	//获取下拉列表
	DictClassifyListJsonVO::Wrapper execGetDictClassifyList(const DictClassifyQuery::Wrapper& query, const PayloadDTO& payload);
	
	DictClassifyPageJsonVO::Wrapper execQueryDictClassify(const DictClassifyQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddDictClassify(const DictClassifyDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyDictClassify(const DictClassifyDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveDictClassify(const UInt64& id);
	//// 3.3 演示批量删除数据
	//Uint64JsonVO::Wrapper execRemoveMoreDictClassify(const DictClassifyDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DICTCLASSIFY_CONTROLLER_