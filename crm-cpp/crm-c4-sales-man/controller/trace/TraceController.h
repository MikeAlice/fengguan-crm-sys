#pragma once
#ifndef _TRACECONTROLLER_H_
#define _TRACECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/trace/AddTraceDTO.h"
#include "domain/dto/trace/ModifyTraceDTO.h"
#include "domain/dto/trace/GetTraceDTO.h"
#include "domain/dto/trace/TraceDTO.h"
#include "domain/dto/trace/ListTraceDTO.h"
#include "domain/vo/trace/GetPageVO.h"
#include "domain/query/trace/TraceQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

#ifndef TRA_PRFIX
#define TRA_PRFIX(_app_) "/crm-c4-sales-man" _app_
#endif 

//增加跟踪记录接口实现
class TraceController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TraceController);

public:
	// 定义接口
	//增加跟踪记录
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("trace.add-trace.summary"), addTrace, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, TRA_PRFIX("/add-trace"), addTrace, BODY_DTO(AddTraceDTO::Wrapper, dto), execAddTrace(dto, authObject->getPayload()));
	//修改跟踪记录
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("trace.modify-trace.summary"), modifyTrace, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, TRA_PRFIX("/modify-trace"), modifyTrace, BODY_DTO(ModifyTraceDTO::Wrapper, dto), execModifyTrace(dto, authObject->getPayload()));

	//获取跟踪记录
	//定义查询接口描述
	ENDPOINT_INFO(queryGet) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("trace.get-trace.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TracePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "AC", ZH_WORDS_GETTER("trace.field.AC"), "liming", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "CS", ZH_WORDS_GETTER("trace.field.CS"), 12, false);
		API_DEF_ADD_QUERY_PARAMS(String, "CContent", ZH_WORDS_GETTER("trace.field.CContent"), "GOOD", false);

		/*
		多一个id字段(特殊标记区别人与人)
		API_DEF_ADD_QUERY_PARAMS(String, "NT", ZH_WORDS_GETTER("trace.field.NT"), "2024.10.23", false);
		*/
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, TRA_PRFIX("/get"), queryGet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, TraceQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGet(userQuery, authObject->getPayload()));
	}

	// 定义跟踪记录删除接口描述
	ENDPOINT_INFO(traceDelete) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("trace.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "trace_id", ZH_WORDS_GETTER("trace.field.trace_id"), 1, true);
	}
	// 定义跟踪记录删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/crm-c4-sales-man/delete-trace/{trace_id}", traceDelete, PATH(UInt64, trace_id), execTraceDelete(trace_id));

	// 定义跟踪记录批量删除接口描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("trace.delete.list"), traceListDelete, Uint64JsonVO::Wrapper);
	// 定义跟踪记录删除接口处理
	API_HANDLER_ENDPOINT(API_M_DEL, "/crm-c4-sales-man/delete-tracelist", traceListDelete, BODY_DTO(ListTraceDTO::Wrapper,dto), execListTraceDelete(dto));

	// 定义一个跟踪记录列表文件下载接口
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tracefile.download.summary"));
		//API_DEF_ADD_COMMON("tracefile-download", Void);
	}
	// 定义端点
	ENDPOINT(API_M_GET, TRA_PRFIX("/downloadfile-trace"), downloadFile) {
		return execDownloadFile();
	}

private: // 定义接口执行函数
	//增加跟踪记录
	BooleanJsonVO::Wrapper execAddTrace(const AddTraceDTO::Wrapper& dto, const PayloadDTO& payload);
	//修改跟踪记录
	BooleanJsonVO::Wrapper execModifyTrace(const ModifyTraceDTO::Wrapper& dto, const PayloadDTO& payload);
	//分页
	TracePageJsonVO::Wrapper execQueryGet(const TraceQuery::Wrapper& query, const PayloadDTO& payload);

	//执行跟踪记录删除处理
	Uint64JsonVO::Wrapper execTraceDelete(const UInt64& trace_id);
	//执行批量跟踪记录删除处理
	Uint64JsonVO::Wrapper execListTraceDelete(const ListTraceDTO::Wrapper& dto);
	// 执行跟踪记录文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_TRACECONTROLLER_H_