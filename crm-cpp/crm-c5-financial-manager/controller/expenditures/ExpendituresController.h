/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/19
 @FileName:ExpendituresController
 @version:1.0
 
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

#ifndef EXPENDITURESCONTROLLER_H__
#define EXPENDITURESCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/expenditures/ExpendituresDTO.h"
#include "domain/query/expenditures/ExpendituresQuery.h"
#include "domain/vo/expendituresquery/ExpendituresQueryPageJsonVO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Expenditures控制器：操作费用支出单
 * 负责人：云隐、是个天才
 */
class ExpendituresController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ExpendituresController);
	// 3 定义接口
public:
	// 删除单据（支持批量删除） 负责人：云隐
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/financial-manager/delete-expenditures-invoices", deleteInvoices, BODY_DTO(List<DelExpendituresDTO::Wrapper>, dto), execDeleteInvoices(dto, authObject->getPayload()));
	ENDPOINT_INFO(deleteInvoices) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.delete.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 导出单据 负责人：云隐
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/export-expenditures-invoices", exportInvoices, BODY_DTO(List<ExportExpenditures::Wrapper>, dto), execExportInvoices(dto, authObject->getPayload()));
	ENDPOINT_INFO(exportInvoices) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.export.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		/*
		// 定义表单参数描述
		info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("expenditures.field.type");
		info->queryParams["type"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.type")));
		info->queryParams["type"].required = false;

		info->queryParams.add<String>("money").description = ZH_WORDS_GETTER("expenditures.field.money");
		info->queryParams["money"].addExample("default", String("100"));
		info->queryParams["money"].required = false;

		info->queryParams.add<String>("bank").description = ZH_WORDS_GETTER("expenditures.field.bank");
		info->queryParams["bank"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.bank")));
		info->queryParams["bank"].required = false;

		info->queryParams.add<String>("latest_happen_date").description = ZH_WORDS_GETTER("expenditures.field.latest_happen_date");
		info->queryParams["latest_happen_date"].addExample("default", String("30"));
		info->queryParams["latest_happen_date"].required = false;
		
		info->queryParams.add<String>("latest_create_time").description = ZH_WORDS_GETTER("expenditures.field.latest_create_time");
		info->queryParams["latest_create_time"].addExample("default", String("30"));
		info->queryParams["latest_create_time"].required = false;

		info->queryParams.add<String>("create_user").description = ZH_WORDS_GETTER("expenditures.field.create_user");
		info->queryParams["create_user"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.create_user")));
		info->queryParams["create_user"].required = false;

		info->queryParams.add<String>("intro").description = ZH_WORDS_GETTER("expenditures.field.intro");
		info->queryParams["intro"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.intro")));
		info->queryParams["intro"].required = false;
		*/
	}

	//新增单据 负责人：是个天才
	ENDPOINT_INFO(addInvoices) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/add-expenditures-invoices", addInvoices,
		BODY_DTO(AddExpendituresDTO::Wrapper, dto), execAddInvoices(dto, authObject->getPayload()));

	//获取单据列表 负责人：是个天才
	ENDPOINT_INFO(queryInvoices) {
	//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.query.summary"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		//定义相应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpendituresPageJsonVO);
		//定义分页参数
		API_DEF_ADD_PAGE_PARAMS();
		//定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String,"bank",ZH_WORDS_GETTER("expenditures.field.bank"),"bank", false);
		API_DEF_ADD_QUERY_PARAMS(Int32,"latest_happen_date",ZH_WORDS_GETTER("expenditures.field.latest_happen_date"),30,false);
		API_DEF_ADD_QUERY_PARAMS(Int32,"latest_create_time",ZH_WORDS_GETTER("expenditures.field.latest_create_time"),30,false);
		API_DEF_ADD_QUERY_PARAMS(Int32,"money",ZH_WORDS_GETTER("expenditures.field.money"),0,false);
		API_DEF_ADD_QUERY_PARAMS(String,"intro",ZH_WORDS_GETTER("expenditures.field.intro"),"intro", false);
	}
	
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "financial-manager/query-invoices",
		queryInvoices, ExpendituresPageQuery, execQueryInvoices(query));
private:
	// 在此添加定义
	Uint64JsonVO::Wrapper execDeleteInvoices(const List<DelExpendituresDTO::Wrapper>& dto, const PayloadDTO& payload);	//删除单据（支持批量删除）  负责人：云隐
	StringJsonVO::Wrapper execExportInvoices(const List<ExportExpenditures::Wrapper>& dto, const PayloadDTO& payload);	//导出单据					负责人：云隐
	ExpendituresPageJsonVO::Wrapper execQueryInvoices(const ExpendituresPageQuery::Wrapper query);			//获取单据列表 负责人：是个天才
	Uint64JsonVO::Wrapper execAddInvoices(const AddExpendituresDTO::Wrapper dto, const PayloadDTO& payload);//新增单据	   负责人：是个天才
};



// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // EXPENDITURESCONTROLLER_H__