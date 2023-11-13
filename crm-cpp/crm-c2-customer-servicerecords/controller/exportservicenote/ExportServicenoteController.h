#pragma once
#ifndef _EXPORTSERVICENOTE_CONTROLLER_H_
#define _EXPORTSERVICENOTE_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "service/exportservicenote/ExportServiceNoteService.h"
#include "domain/dto/service/ServiceBaseDTO.h"
#include "domain/dto/service/ServiceDetailDTO.h"
#include "domain/vo/service/ServiceVO.h"
#include"domain/query/exportservicenote/ExportServiceNoteQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)


/**
 * 导出服务记录Controller
 * 负责人: 会跑的鱼
 */
class ExportServicenoteController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportServicenoteController);
public:
	// 定义接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-servicerecords/export-servicenote", exportServicenote, BODY_DTO(ExportServiceNoteQuery::Wrapper, query), execExportServiceNote(query, authObject->getPayload()));
	//ENDPOINT(API_M_GET, "/customer-servicerecords/export-servicenote", exportServicenote, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//	// 解析查询参数为Query领域模型
	//	API_HANDLER_QUERY_PARAM(userQuery, ExportServiceNoteQuery, queryParams);
	//	// 呼叫执行函数响应结果
	//	API_HANDLER_RESP_VO(execExportServiceNote(userQuery, authObject->getPayload()));
	//}
	// 定义接口描述
	ENDPOINT_INFO(exportServicenote) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("service.controller.export-servicenote.summary"),StringJsonVO::Wrapper);
	}
	//// 定义接口描述
	//ENDPOINT_INFO(exportServicenote) {
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("service.controller.export-servicenote.summary"));
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//	// 定义查询参数描述
	//	API_DEF_ADD_QUERY_PARAMS(List<Int32>, "service_id_list", ZH_WORDS_GETTER("service.field.service_id_list"), { 1 }, false);
	//	API_DEF_ADD_QUERY_PARAMS(Int32, "customer_id", ZH_WORDS_GETTER("service.field.customer_id"), 0, false);
	//	API_DEF_ADD_QUERY_PARAMS(Int32, "service_id", ZH_WORDS_GETTER("service.field.service_id"), 0, false);
	//	/*API_DEF_ADD_QUERY_PARAMS(Int32, "services", ZH_WORDS_GETTER("service.field.services"), 0, true);
	//	API_DEF_ADD_QUERY_PARAMS(Int32, "servicesmodel", ZH_WORDS_GETTER("service.field.servicesmodel"), 0, true);
	//	API_DEF_ADD_QUERY_PARAMS(String, "service_time", ZH_WORDS_GETTER("service.field.service_time"), "xxxx-xx-xx", true);
	//	API_DEF_ADD_QUERY_PARAMS(String, "tlen", ZH_WORDS_GETTER("service.field.tlen"), "0", true);
	//	API_DEF_ADD_QUERY_PARAMS(String, "content", ZH_WORDS_GETTER("service.field.content"), "fix", true);*/
	//}

	
private:
	// 定义导出接口执行函数
	StringJsonVO::Wrapper execExportServiceNote(ExportServiceNoteQuery::Wrapper query,const PayloadDTO& payload);
	
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTSERVICENOTE_CONTROLLER_H_
