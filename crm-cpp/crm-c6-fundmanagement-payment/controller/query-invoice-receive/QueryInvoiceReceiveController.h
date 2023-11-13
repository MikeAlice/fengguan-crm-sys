#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 11:31:45

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _GETRECEIPTRECORDCONTROLLER_H_
#define _GETRECEIPTRECORDCONTROLLER_H_

#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/query-invoice-receive/FinInvoiceReceivePageJsonVO.h"
#include "domain/query/query-invoice-receive/QueryInvoiceReceiveQuery.h"
#include "service/query-invoice-rece/QueryInvoiceReceiveService.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryInvoiceReceiveController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(QueryInvoiceReceiveController);
public:
	// 3 定义接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryInvoiceReceive){
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_invoice_rece.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FinInvoiceReceivePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//收票日期、创建日期、合同标题、供应商名称、金额
		API_DEF_ADD_QUERY_PARAMS(String, "rece_date", ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date"), "2023-10-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("fin_invoice_rece.field.create_time"), "2023-10-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name"), u8"天河一号", false);
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name"), u8"上海八达", false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "money", ZH_WORDS_GETTER("fin_invoice_rece.field.money"), , false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/payment/invoice/query", queryInvoiceReceive, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(invoiceReceiveQuery, QueryInvoiceReceiveQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInvoiceReceive(invoiceReceiveQuery, authObject->getPayload()));
	}
private:
	FinInvoiceReceivePageJsonVO::Wrapper execQueryInvoiceReceive(const QueryInvoiceReceiveQuery::Wrapper& query, const PayloadDTO& payload)
	{
		// 定义一个service
		QueryInvoiceReceiveService service;
		auto result = service.listAll(query);
		// 响应结果
		auto jvo = FinInvoiceReceivePageJsonVO::createShared();
		jvo->success(result);
		return jvo;
	}
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETRECEIPTRECORDCONTROLLER_H_

