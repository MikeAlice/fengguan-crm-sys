#pragma once
/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/21 12:59:38

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
#ifndef INCOMECONTROLLER_H_
#define INCOMECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/other_income_statement/IncomeDTO.h"
#include "domain/vo/other_income_statement/IncomePageJsonVO.h"
#include "domain/query/other_income_statement/IncomeQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Income控制器：操作其他收入单
 */
class IncomeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(IncomeController);
	// 3 定义接口
public:
	
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/insert-income", insertIncome, BODY_DTO(IncomeDTO::Wrapper, dto), execInsertIncome(dto, authObject->getPayload()));
	ENDPOINT_INFO(insertIncome) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("other_income_statement.controller.post.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	}
	ENDPOINT_INFO(queryIncome) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("other_income_statement.controller.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(IncomePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int16, "record_id", ZH_WORDS_GETTER("other_income_statement.field.record_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int16, "type_id", ZH_WORDS_GETTER("other_income_statement.field.type_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int16, "bank_id", ZH_WORDS_GETTER("other_income_statement.field.bank_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "money", ZH_WORDS_GETTER("other_income_statement.field.money"), 1.00, false);
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("other_income_statement.field.record_id"), "nothing", false);
		API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("other_income_statement.field.happen_date"), "2023-10-21", false);
		API_DEF_ADD_QUERY_PARAMS(Int16, "create_user_id", ZH_WORDS_GETTER("other_income_statement.field.create_user_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("other_income_statement.field.create_time"), "2023-10-21 15:43:12", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/financial-manager/query-income", queryIncome, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, IncomePageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryIncome(userQuery, authObject->getPayload()));
	}
private:
	// 在此添加定义
	Uint64JsonVO::Wrapper execInsertIncome(const IncomeDTO::Wrapper& dto, const PayloadDTO& payload);
	IncomePageJsonVO::Wrapper execQueryIncome(const IncomePageQuery::Wrapper& dto, const PayloadDTO& payload);// 分页查询其他收入单，负责人：洒水水
	Uint64JsonVO::Wrapper execModifyIncome(const IncomeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveIncome(const UInt64& id);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // INCOMECONTROLLER_H_




