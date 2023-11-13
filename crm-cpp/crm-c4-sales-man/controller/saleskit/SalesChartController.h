#pragma once

#ifndef _SALESCHART_CONTROLLER_
#define _SALESCHART_CONTROLLER_

#include"domain/vo/BaseJsonVO.h"
#include"domain/dto/saleskit/SalesChartDTO.h"
#include"domain/vo/saleskit/SalesChartVO.h"
#include"domain/query/saleskit/SalesChartQuery.h"

#include"domain/dto/saleskit/NumberCountingDTO.h"
#include"domain/vo/saleskit/NumberCountingVO.h"
#include"domain/query/saleskit/NumberCountingQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SalesChartController :public oatpp::web::server::api::ApiController //1.继承控制器
{
	//2.定义控制器访问入口
	API_ACCESS_DECLARE(SalesChartController);
	//3.定义接口
public:
	//定义获取销售榜接口描述
	ENDPOINT_INFO(querySalesChart) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sales-chart.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SalesChartJsonVO);
		//定义请求参数
		//API_DEF_ADD_QUERY_PARAMS(String, "date", ZH_WORDS_GETTER("count-num.field.time-slot"), ZH_WORDS_GETTER("time.this-week"), false);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "date_id", ZH_WORDS_GETTER("count-num.field.time-slot"), 1, false);
	}
	//eg: API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("sales-chart.query.summary"), querySalesChart, Uint64JsonVO::Wrapper);

	//定义获取销售榜接口处理
	//定义查询端点
	/*
	ENDPOINT(API_M_GET, "/querySalesChart", querySalesChart, QUERIES(QueryParams, params)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(query, SalesChartQuery, params);
		//响应结果（呼叫执行函数）
		API_HANDLER_RESP_VO(execQuerySalesChart(query));
	}
	*/
	API_HANDLER_ENDPOINT(API_M_GET, "/crm-c4-sales-man/querySalesChart", querySalesChart, QUERY(UInt64, date_id), execQuerySalesChart(date_id));
	//API_HANDLER_ENDPOINT(API_M_DEL, "/querySalesChart", querySalesChart, BODY_DTO(SalesChartQuery::Wrapper, dto), execQuerySalesChart(dto));

	// 定义数量统计接口描述
	ENDPOINT_INFO(queryNumberCounting) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("count-num.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(NumberCountingJsonVO);
		//定义请求参数
		//API_DEF_ADD_QUERY_PARAMS(String, "date", ZH_WORDS_GETTER("count-num.field.time-slot"), ZH_WORDS_GETTER("time.this-week"), false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "date_id", ZH_WORDS_GETTER("count-num.field.time-slot"), 1, false);
	}

	//定义数量统计查询端点（处理）
	/*
	ENDPOINT(API_M_GET, "/queryNumberCounting", queryNumberCounting, QUERIES(QueryParams, params)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(query, NumberCountingQuery, params);
		//响应结果（呼叫执行函数）
		API_HANDLER_RESP_VO(execQueryNumberCounting(query));
	}
	*/

	API_HANDLER_ENDPOINT(API_M_GET, "/crm-c4-sales-man/queryNumberCounting", queryNumberCounting, QUERY(UInt64, date_id), execQueryNumberCounting(date_id));

private://定义接口函数
	// 查询销售榜
	SalesChartJsonVO::Wrapper execQuerySalesChart(const UInt64& date_id);
	// 查询数量统计
	NumberCountingJsonVO::Wrapper execQueryNumberCounting(const UInt64& date_id);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //!_SALESCHART_CONTROLLER