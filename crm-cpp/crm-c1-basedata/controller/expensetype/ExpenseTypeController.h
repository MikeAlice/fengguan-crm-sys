#pragma once

#ifndef _EXPENSETYPE_CONTROLLER_
#define _EXPENSETYPE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/expensetype/ExpenseTypeDTO.h"
#include"domain/query/expensetype/ExpenseTypeQuery.h"
#include"domain/vo/expensetype/ExpenseTypeVO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 费用支出控制器
 */
class ExpenseTypeController : public oatpp::web::server::api::ApiController // 继承控制器
{
	API_ACCESS_DECLARE(ExpenseTypeController);
	
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryExpenseType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.get.summarytype"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseTypePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expensetype.field.name"), "li ming", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/expensetype/query-expensetype", queryExpenseType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpenseTypeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryExpenseType(userQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述 
	ENDPOINT_INFO(addExpenseType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/expensetype/add-expensetype", addExpenseType, BODY_DTO(ExpenseTypeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddExpenseType(dto));
	}

	// 定义修改类型接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("expensetype.modify-type.summary"), modifyType, Uint64JsonVO::Wrapper);
	// 定义修改类型接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/expensetype/modify-type", modifyType, BODY_DTO(ExpenseTypeDTO::Wrapper, dto), execModifyExpenseType(dto));

	//  定义删除接口描述
	ENDPOINT_INFO(removeExpenseType) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expensetype.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("expensetype.field.id"), 1, true);
	}
	//  定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/expensetype/delete-expensetype/{id}", removeExpenseType, PATH(UInt64, id), execRemoveType(id));
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryALLExpenseTree) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseTreeJsonVO);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/expensetype/query-all-expensetype", queryALLExpenseTree, API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryALLExpenseTree(authObject->getPayload()));
	}




	// 3.1 定义树结构查询接口描述
	ENDPOINT_INFO(queryExpenseTree) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.get.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseTreeJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "parentid", ZH_WORDS_GETTER("expensetype.field.parentid"), "0", true);
		API_DEF_ADD_QUERY_PARAMS(String, "depth", ZH_WORDS_GETTER("expensetype.field.depth"), "0", true);
	}
	// 3.2 定义树结构查询接口处理
	ENDPOINT(API_M_GET, "/expensetype/query-expensetree", queryExpenseTree, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {

		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(Query, ExpenseQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryExpenseTree(Query, authObject->getPayload()));
	}

private:
	// 3.3 演示分页查询数据
	ExpenseTypePageJsonVO::Wrapper execQueryExpenseType(const ExpenseTypeQuery::Wrapper& query, const PayloadDTO& payload);
	//3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddExpenseType(const ExpenseTypeDTO::Wrapper& dto);
	// 修改数据
	Uint64JsonVO::Wrapper execModifyExpenseType(const ExpenseTypeDTO::Wrapper& dto);
	// 删除数据
	Uint64JsonVO::Wrapper execRemoveType(const UInt64& id);
	//查询全部结构树
	ExpenseTreeJsonVO::Wrapper execQueryALLExpenseTree(const PayloadDTO& payload);
	//指定父节点和查询深度的查询
	ExpenseTreeJsonVO::Wrapper execQueryExpenseTree(ExpenseQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPENSETYPE_CONTROLLER_