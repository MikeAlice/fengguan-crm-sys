#pragma once
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_
#include "domain/vo/JsonVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class TestController :public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(TestController);
public://定义接口
	//定义测试查询端口描述
	ENDPOINT_INFO(queryTest) {
		//描述标题
		info->summary = "query test1";
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义相应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//定义请求参数
		API_DEF_ADD_PAGE_PARAMS();
	}
	//定义测试查询端口
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, PageQuery, params);
		//相应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private://定义接口执行函数  
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query) {
		auto result = StringJsonVO::createShared();
		result->success(String("query test"));
		return result;
	}
		
	
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !1

