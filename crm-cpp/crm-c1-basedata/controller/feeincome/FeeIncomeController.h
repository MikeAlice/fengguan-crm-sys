#pragma once
#ifndef _FeeIncome_CONTROLLER_
#define _FeeIncome_CONTROLLER_
#include "ApiHelper.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/feeincome/FeeIncomeQuery.h"
#include "domain/dto/feeincome/FeeIncomeDTO.h"
#include "domain/vo/feeincome/FeeIncomeTreeVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class FeeIncomeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(FeeIncomeController);
	// 3 定义接口
public:
	// 3.1 定义获取类型列表(分页 + 条件)接口描述
	ENDPOINT_INFO(queryFeeIncome) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.query-type.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeIncomePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("FeeIncomeType.field.name"), "收入", false);
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "parentID", ZH_WORDS_GETTER("FinIncomeType.field.parentID"), "1", false);
	}
	// 3.1 获取类型列表(分页 + 条件)
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, OIC_PRFIX("/query-type"), queryFinIncomeType, BODY_DTO(FinIncomeTypeQuery::Wrapper, query), execQueryType(query, authObject->getPayload()));
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET,"/feeincome/query-feeincome", queryFeeIncome, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, FeeIncomeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryType(userQuery, authObject->getPayload()));
	}
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryALLFeeIncome) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeIncomeTreeJsonVO);
	
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/feeincome/query-all-feeincome", queryALLFeeIncome, API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryALLFeeIncome(authObject->getPayload()));
	}
	// 3.1 定义新增接口描述 
	ENDPOINT_INFO(addFeeIncome) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/feeincome/add-feeincome", addFeeIncome, BODY_DTO(FeeIncomeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddFeeIncome(dto));
	}
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("feeincome.put.summary"), modifyFeeIncome, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/feeincome/modify-feeincome", modifyFeeIncome, BODY_DTO(FeeIncomeDTO::Wrapper, dto), execModifyFeeIncome(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeFeeIncome) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("feeincome.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("feeincome.field.id"), 1, true);
	}
	//  定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/feeincome/delete-feeincome/{id}", removeFeeIncome, PATH(UInt64, id), execRemoveFeeIncome(id));




	// 3.1 定义树结构查询接口描述
	ENDPOINT_INFO(queryALLFeeIncomeTree) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.get.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeIncomeTreeJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "parentid", ZH_WORDS_GETTER("feeincome.field.parentid"), "0", true);
		API_DEF_ADD_QUERY_PARAMS(String, "depth", ZH_WORDS_GETTER("feeincome.field.depth"), "0", true);
	}
	// 3.2 定义树结构查询接口处理
	ENDPOINT(API_M_GET, "/feeincome/query-all-feeincomeTree", queryALLFeeIncomeTree, QUERIES(QueryParams, queryParams),API_HANDLER_AUTH_PARAME) {
	
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(Query, FeeIncomeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryALLFeeIncomeTree(Query, authObject->getPayload()));
	}

	
private:
	FeeIncomePageJsonVO::Wrapper execQueryType(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload);
	FeeIncomeTreeJsonVO::Wrapper execQueryALLFeeIncome(const PayloadDTO& payload);
	FeeIncomeTreeJsonVO::Wrapper execQueryALLFeeIncomeTree(FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload);
	//// 3.3 演示分页查询数据
	//FeeIncomePageJsonVO::Wrapper execQueryFeeIncome(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload);
	//3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddFeeIncome(const FeeIncomeDTO::Wrapper& dto);
	//3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyFeeIncome(const FeeIncomeDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveFeeIncome(const UInt64& id);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_