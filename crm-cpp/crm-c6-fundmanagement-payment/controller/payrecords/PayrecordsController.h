#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _PAYRECORDS_CONTROLLER_
#define _PAYRECORDS_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/payrecords/PayrecordsVO.h"
#include "domain/query/payrecords/PayrecordsQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class PayrecordsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PayrecordsController);
public:
	ENDPOINT_INFO(queryPayrecords) {
		// 定义接口标题
		//info->summary = u8"分页查询付款记录列表";
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payrecords.controller.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PayrecordsPageJsonVO);
		// 定义分页查询参数
		API_DEF_ADD_PAGE_PARAMS();
		// 付款时间
		API_DEF_ADD_QUERY_PARAMS(String, "pay_date", ZH_WORDS_GETTER("pay.field.pay_date"), "2023-10-17", false);
		// 创建时间
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("pay.field.create_time"), "2023-10-26", false);
		// 采购合同名称
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("pay.field.contract_name"), u8"天河一期", false);
		// 供应商名称
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("pay.field.supplier_name"), u8"上海八达", false);
		// 金额
		API_DEF_ADD_QUERY_PARAMS(UInt64, "money", ZH_WORDS_GETTER("pay.field.money"), 123, false);
		
	}
	ENDPOINT(API_M_GET, "/payment/pay-record/page-query", queryPayrecords, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(payrecordsQuery, PayrecordsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPayrecords(payrecordsQuery, authObject->getPayload()));
	}
private:
	PayrecordsPageJsonVO::Wrapper execQueryPayrecords(const PayrecordsQuery::Wrapper& query, const PayloadDTO& payload); 
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_