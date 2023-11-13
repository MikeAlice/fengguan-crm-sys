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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/other_income_statement/Other_income_statementDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class Other_income_statementController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(Other_income_statementController);
	// 3 定义接口
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/financial-manager/delete-invoices", delInvoices, BODY_DTO(List<DelOisDTO::Wrapper>, dto), execDelInvoices(dto, authObject->getPayload()));
	ENDPOINT_INFO(delInvoices) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("other_income_statement.controller.delete.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("other_income_statement.field.record_id"), 24, true);
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "type_id", ZH_WORDS_GETTER("other_income_statement.field.type_id"), 24, true);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "money", ZH_WORDS_GETTER("other_income_statement.field.money"), 24.0, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "bank_id", ZH_WORDS_GETTER("other_income_statement.field.bank_id"), "11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("other_income_statement.field.happen_date"), "11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_user_id", ZH_WORDS_GETTER("other_income_statement.field.create_user_id"), "11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("other_income_statement.field.create_time"), "11", true);
	}

	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/export-data", exportdata, BODY_DTO(List<ExpOisDTO::Wrapper>, dto), execExportdata(dto, authObject->getPayload()));
	ENDPOINT_INFO(exportdata) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("other_income_statement.controller.export.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("other_income_statement.field.record_id"), 24, true);
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "type_id", ZH_WORDS_GETTER("other_income_statement.field.type_id"), 24, true);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "money", ZH_WORDS_GETTER("other_income_statement.field.money"), 24.0, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "bank_id", ZH_WORDS_GETTER("other_income_statement.field.bank_id"), "11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("other_income_statement.field.happen_date"), "11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_user_id", ZH_WORDS_GETTER("other_income_statement.field.create_user_id"), "11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("other_income_statement.field.create_time"), "11", true);
	}
	
private:
	Uint64JsonVO::Wrapper execDelInvoices(const List<DelOisDTO::Wrapper>& dto, const PayloadDTO& payload);    // 删除功能
	StringJsonVO::Wrapper execExportdata(const List<ExpOisDTO::Wrapper>& dto, const PayloadDTO& payload);    // 导出功能
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_