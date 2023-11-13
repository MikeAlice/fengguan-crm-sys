#ifndef FLOWRECORDCONTROLLER_H__
#define FLOWRECORDCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/flowrecord/FlowrecordDTO.h"
#include "domain/vo/flowrecord/FlowrecordPageJsonVO.h"
#include "domain/query/flowrecord/FlowrecordQuery.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Flowrecord控制器：操作流水记录
 * 负责人：智商局局长
 */
class FlowrecordController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(FlowrecordController);
	// 3 定义接口
public:
	// 分页查询流水记录 负责人：智商局局长
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/financial-manager/query-flowrecord", queryFlowrecord, FlowrecordPageQuery, execQueryFlowrecord(query, authObject->getPayload()));
	
	ENDPOINT_INFO(queryFlowrecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("flowrecord.controller.query.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(FlowrecordPageJsonVO);
		//定义分页参数
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "bank_id", ZH_WORDS_GETTER("flowrecord.field.bank_id"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "income", ZH_WORDS_GETTER("flowrecord.field.income"), , false);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "expenditure", ZH_WORDS_GETTER("flowrecord.field.expenditure"),, false);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "surplus", ZH_WORDS_GETTER("flowrecord.field.surplus"), , false);
		//API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("flowrecord.field.type"),u8"", false);
		API_DEF_ADD_QUERY_PARAMS(String, "connect_id", ZH_WORDS_GETTER("flowrecord.field.connect_id"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_user", ZH_WORDS_GETTER("flowrecord.field.create_user"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("flowrecord.field.create_time"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "total_income", ZH_WORDS_GETTER("flowrecord.field.total_income"), 100, false);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "total_expenditure", ZH_WORDS_GETTER("flowrecord.field.total_expenditure"), 100, false);
	}

	//导出流水记录 负责人：智商局局长
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/export-flowrecord",exportFlowrecord, BODY_DTO(List<FlowrecordExportDTO::Wrapper>, dto), execExportFlowrecord(dto, authObject->getPayload()));
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/financial-manager/query-flowrecord", exportFlowrecord, FlowrecordPageQuery, execExportFlowrecord(query, authObject->getPayload()));
	
	ENDPOINT_INFO(exportFlowrecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("flowrecord.controller.export.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}

private:
	// 在此添加定义

	FlowrecordPageJsonVO::Wrapper execQueryFlowrecord(const FlowrecordPageQuery::Wrapper& query, const PayloadDTO& payload); // 获取流水记录 负责人：智商局局长
	StringJsonVO::Wrapper execExportFlowrecord(const List<FlowrecordExportDTO::Wrapper>& dto, const PayloadDTO& payload);  // 导出流水记录 负责人：智商局局长
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 