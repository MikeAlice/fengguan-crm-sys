#pragma once
/*
 @Author: linglan
 @Date: 2023/10/23 20:48:11

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
#ifndef _QUERYPAYMENTPLANCONTROLLER_H_
#define _QUERYPAYMENTPLANCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/payment_plan/PaymentPlanVO.h"
#include "domain/query/payment_plan/PaymentPlanQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

//查询付款计划信息(分页) 负责人：灵岚
class QueryPaymentPlanController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryPaymentPlanController);
public: // 定义接口
	//定义端点描述
	ENDPOINT_INFO(queryPaymentPlans)
	{
		// 该端点的描述信息
		info->summary = u8"查询付款计划";
		//添加安全验证
		API_DEF_ADD_AUTH();
		//定义分页查询参数描述(请求)
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述(请求)
		// 编号
		API_DEF_ADD_QUERY_PARAMS(Int32, "plan_id", ZH_WORDS_GETTER("paymentplan.field.plan_id"), 123, false);
		// 采购合同名称
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("paymentplan.field.contract_name"), u8"天河一期", false);
		// 供应商号
		API_DEF_ADD_QUERY_PARAMS(Int32, "supplier_id", ZH_WORDS_GETTER("paymentplan.field.supplier_id"), 123, false);
		// 供应商名称
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("paymentplan.field.supplier_name"), u8"上海八达", false);
		// 金额
		API_DEF_ADD_QUERY_PARAMS(Int32, "money", ZH_WORDS_GETTER("paymentplan.field.money"), 123, false);
		// 计划付款日期
		API_DEF_ADD_QUERY_PARAMS(String, "plan_date", ZH_WORDS_GETTER("paymentplan.field.plan_date"), "2023-10-17", false);
		// 是否付款
		API_DEF_ADD_QUERY_PARAMS(String, "ifpay", ZH_WORDS_GETTER("paymentplan.field.ifpay"), u8"-1", false);
		// 创建时间
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("paymentplan.field.create_time"), "2023-10-25 19:42:50", false);


		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PaymentPlanPageJsonVO);//PaymentPlanPageJsonVO为返回值，与executeQueryTest返回值类型一致
	}

	// 定义查询付款计划信息接口端点处理
	ENDPOINT(API_M_GET, "/payment/pay-plan/query", queryPaymentPlans, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(paymentPlanQuery, PaymentPlanQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryPaymentPlans(paymentPlanQuery, authObject->getPayload()));
	}

private: // 定义接口执行函数

	// 查询所有
	PaymentPlanPageJsonVO::Wrapper executeQueryPaymentPlans(const PaymentPlanQuery::Wrapper& paymentPlanQuery, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYPAYMENTPLANCONTROLLER_H_
