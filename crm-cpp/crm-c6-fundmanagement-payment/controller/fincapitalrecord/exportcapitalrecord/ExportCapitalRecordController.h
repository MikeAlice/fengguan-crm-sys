//#pragma once
//#pragma once
//
//#ifndef _EXPORT_CAPITAL_RECORD_CONTROLLER_H_
//#define _EXPORT_CAPITAL_RECORD_CONTROLLER_H_
//#include "domain/vo/BaseJsonVO.h"
//#include "ApiHelper.h"
//#include "Macros.h"
//#include "ServerInfo.h"
//#include "domain/query/capitalRecordFile/ExportCapitalRecordQuery.h"
//
//#include OATPP_CODEGEN_BEGIN(ApiController)
//class ExportCapitalRecordController : public oatpp::web::server::api::ApiController
//{
//	// 定义控制器访问入口
//	API_ACCESS_DECLARE(ExportCapitalRecordController);
//public:// 定义接口
//	// 定义导出数据接口	负责人：超能
//	ENDPOINT(API_M_GET, "/payment/invoice/export", queryCaptalRecordFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
//		// 解析查询参数为Query领域模型
//		API_HANDLER_QUERY_PARAM(capitalRecordQuery, ExportCapitalRecordQuery, queryParams);
//		// 呼叫执行函数响应结果
//		API_HANDLER_RESP_VO(execExportCapitalRecord(capitalRecordQuery, authObject->getPayload()));
//	}
//	// 定义导出数据接口描述
//	ENDPOINT_INFO(queryCaptalRecordFile) {
//		// 定义接口标题
//		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.export"));
//		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
//		API_DEF_ADD_AUTH();
//		// 定义响应参数格式
//		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
//		// 定义其他查询参数描述
//		/*API_DEF_ADD_QUERY_PARAMS(Int64, "record_id", ZH_WORDS_GETTER("fin_capital_record.field.record_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(Int64, "type_id", ZH_WORDS_GETTER("fin_capital_record.field.type_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(Int64, "create_user_id", ZH_WORDS_GETTER("fin_capital_record.field.create_user_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(UInt64, "bank_id", ZH_WORDS_GETTER("fin_capital_record.field.bank_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(Int64, "money", ZH_WORDS_GETTER("fin_capital_record.field.money"), 1, false);
//		*/API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("fin_capital_record.field.intro"), "hello1", false);
//		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("fin_capital_record.field.create_time"), "hello2", false);
//		API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("fin_capital_record.field.happen_date"), "hello3", false);
//
//	}
//	// 定义导入客户接口	负责人：超能
//	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/payment/capital/delete", deleteCapitalRecordFile, BODY_STRING(String, filePath), execDeleteCapitalRecordFile(filePath, authObject->getPayload()));
//	// 定义导入客户接口描述
//	ENDPOINT_INFO(deleteCapitalRecordFile) {
//		// 定义接口标题
//		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.deletefile"));
//		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
//		API_DEF_ADD_AUTH();
//		// 定义响应参数格式
//		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
//	}
//private:
//	/**
//	 * 负责人：超能
//	 * 功能描述：将数据保存为Excel文件，上传到文件服务器，并将路径发送到前端
//	 * @param： ExportCapitalRecordQuery::Wrapper   筛选条件
//	 *			PayloadDTO&
//	 *			@return： StringJsonVO  返回文件路径
//	 */
//	StringJsonVO::Wrapper execExportCapitalRecord(ExportCapitalRecordQuery::Wrapper query, const PayloadDTO& playload);
//	/*
//	* 负责人： 超能
//	* 功能描述：将文件服务器上的导出客户Excel表格文件删除
//	* @param： filepath   要删除文件的路径
//	* @return： BooleanJsonVO  返回执行结果
//	*/
//	BooleanJsonVO::Wrapper execDeleteCapitalRecordFile(String filePath, const PayloadDTO& playload);
//};
//
//#include OATPP_CODEGEN_END(ApiController)
//#endif
