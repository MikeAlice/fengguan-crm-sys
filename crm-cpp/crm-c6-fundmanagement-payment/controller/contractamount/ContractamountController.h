#pragma once
#ifndef _CONTRACTAMOUNT_CONTROLLER
#define _CONTRACTAMOUNT_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/contractamount/ContractamountQuery.h"
#include "domain/dto/contractamount/ContractamountDTO.h"
#include "domain/vo/contractamount/ContractamountVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 继承控制器
class ContractamountController : public oatpp::web::server::api::ApiController { 
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ContractamountController);
public:
	// 3.1 定义测试声明式服务调用的接口描述0
	ENDPOINT_INFO(queryContractamount) {
		// 定义接口标题
		//API_DEF_ADD_TITLE(u8"查询合同金额");
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contractamount.controller.title"));
		// // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractamountJsonVO);
		// 定义其他查询参数描述
		// 合同id
		API_DEF_ADD_QUERY_PARAMS(UInt64, "contract_id", ZH_WORDS_GETTER("contractamount.field.contract_id"), 1, true);
		// 类型：付款 OR 回款
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("contractamount.field.type"), "pay", true);
	}
	// 3.2 定义测试声明式服务调用的接口处理
	ENDPOINT(API_M_GET, "/payment/contray/query", queryContractamount, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(contractamountQuery, ContractamountQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryContractamount(contractamountQuery, authObject->getPayload()));
	}
	
private:
	ContractamountJsonVO::Wrapper execQueryContractamount(const ContractamountQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif