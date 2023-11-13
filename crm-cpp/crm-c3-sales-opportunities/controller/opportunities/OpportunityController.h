#ifndef _OPPORTUNITYCONTROLLER_H_
#define _OPPORTUNITYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/getindex/OpportunityDTO.h"
#include "domain/vo/getindex/OpportunityVO.h"
#include "domain/query/getindex/OpportunityQuery.h"
#include "ApiHelper.h"
#include "Macros.h"

#include"domain/dto/getindex/GetSalesOppoDTO.h"
#include "domain/query/getindex/GetSalesOppoQuery.h"
#include "domain/vo/getindex/GetSalesOppoVo.h"
#include "service/Sales/GetSalesOppoService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)



class OpportunityController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(OpportunityController);

public: 
	
	//获取销售机名称会列表（用于输入表单下拉列表）长风
	ENDPOINT_INFO(querySalOppoNameList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.querySalOppoNameList"));	//目录名.controller.接口名称
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetSalesOppoJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "customer_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("opportunities.field.cst_chance.name"), "lt", false);

	}
	ENDPOINT(API_M_GET, "/sales-opportunities/sales-oppo-name-list", querySalOppoNameList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetSalesOppoQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySalOppoNameList(userQuery, authObject->getPayload()));
	}
	
	//获取销售机名称会列表（用于输入表单下拉列表）长风
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales-opportunities/sales-oppo-name-list/{customer_id}", querySalOppoNameList, PATH(UInt32, customer_id), execQuerySalOppoNameList(customer_id));
	//ENDPOINT_INFO(querySalOppoNameList) {
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("opportunities.controller.querySalOppoNameList"), GetSalesOppoJsonVO::Wrapper);
	//	API_DEF_ADD_PATH_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"), 1, false);
	//}


	//导出销售机会 归途
	ENDPOINT_INFO(queryExportSalOpp) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.export-sales-opportunity"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义销售机会查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int16, "chance_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"), 1, false);
	}
	ENDPOINT(API_M_GET, "/sales-opportunities/export-sales-opportunity", queryExportSalOpp, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数queryParams为ExportSupLinkmanQuery类型
		API_HANDLER_QUERY_PARAM(query, OpportunityQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryExportSalOpp(query, authObject->getPayload()));
	}


private: 
	////获取销售机名称会列表（用于输入表单下拉列表）长风
	GetSalesOppoJsonVO::Wrapper execQuerySalOppoNameList(const GetSalesOppoQuery::Wrapper& query, const PayloadDTO& payload);

	//GetSalesOppoJsonVO::Wrapper execQuerySalOppoNameList(const UInt32& customer_id);


	//导出销售机会 归途
	StringJsonVO::Wrapper execQueryExportSalOpp(const OpportunityQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OPPORTUNITYCONTROLLER_H_
