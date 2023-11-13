#ifndef SALEOPPORTController_H__
#define SALEOPPORTCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/saleopport/SaleopportDTO.h"
#include "domain/query/saleopport/SaleopportQuery.h"
#include "domain/vo/saleopportquery/SaleopportQueryPageJsonVO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Saleopport控制器
 */
class SaleopportController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SaleopportController);
	// 3 定义接口
public:
	//获取销售机会列表
	ENDPOINT_INFO(querySalOppList) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.querySalOppList"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		//定义相应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SaleopportPageJsonVO);
		//定义分页参数
		API_DEF_ADD_PAGE_PARAMS();
		//定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "find_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"), "1900-1-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bill_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"), "9999-9-9", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "salestage", ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"), 1, false);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/sales-opportunities/query-invoices",
		querySalOppList, SaleopportPageQuery, execQuerySalOppList(query, authObject->getPayload()));

private:
	// 在此添加定义
	SaleopportPageJsonVO::Wrapper execQuerySalOppList(const SaleopportPageQuery::Wrapper query, const PayloadDTO& payload);			//获取销售机会
	Uint64JsonVO::Wrapper execAddInvoices(const AddSaleopportDTO::Wrapper dto, const PayloadDTO& payload);//新增销售机会   
};



// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // SALEOPPORTCONTROLLER_H__