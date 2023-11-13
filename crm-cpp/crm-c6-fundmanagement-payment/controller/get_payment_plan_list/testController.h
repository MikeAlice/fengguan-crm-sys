#pragma once
/*
 @Author: linglan
 @Date: 2023/10/23 15:25:51

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
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TestController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TestController);
public: // 定义接口
	// 查询测试
	// 定义端点描述
	ENDPOINT_INFO(queryTest) {
		//描述总结
		info->summary = u8"查询测试";
		//定义请求参数
		API_DEF_ADD_PAGE_PARAMS();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);//StringJsonVO为返回值，与executeQueryTest返回值类型一致
	}

	// 定义端点endpoint, 与上面的ENDPOINT_INFO(queryTest)对应,其中queryTest为端点方法名称
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, params)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(query, PageQuery, params);
		//响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // 定义接口执行函数
	// 查询测试
	// queryTest执行函数
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query) {
		auto result = StringJsonVO::createShared();
		result->success("queryTest");
		return result;
	}
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_TESTCONTROLLER_H_