#pragma once
#ifndef _INVOICE_CONTROLLER_
#define _INVOICE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include <ApiHelper.h>
#include "domain/query/PageQuery.h"
#include "domain/vo/invoice/InvoiceVO.h"
#include "domain/query/invoice/InvoiceQuery.h"
#include "../../domain/dto/invoice/InvoiceAddDTO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class InvoiceController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InvoiceController);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(queryInvoice) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Invoice.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InvoicePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "pay_date", ZH_WORDS_GETTER("Invoice.field.pay_date"), "2023/10/24", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("Invoice.field.create_time"), "2023/10/24", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("Invoice.field.contract_name"), "contract_name", false);
	}
	// 3.2 定义查询接口处理//这里api parame有疑问
	ENDPOINT(API_M_GET, "/collection-man/Invoice/qurery", queryInvoice, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, InvoiceQuery,params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInvoice(userQuery, authObject->getPayload()));
	}


	ENDPOINT_INFO(addInvoice) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Invoice.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/collection-man/Invoice/add", addInvoice, BODY_DTO(InvoiceAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddInvoice(dto, authObject->getPayload()));
	}


private:
	// 3.3 演示新增数据
	InvoicePageJsonVO::Wrapper execQueryInvoice(const InvoiceQuery::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddInvoice(const InvoiceAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif