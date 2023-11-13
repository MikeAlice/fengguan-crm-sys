#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chou
 @Date: 2023/10/23 14:40:19

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
#ifndef _COLLECTIONPLANSCONTROLLER_H_
#define _COLLECTIONPLANSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/collectionplans/AddCollectionPlanDTO.h"
#include "domain/dto/collectionplans/GetCollectionPlanListDTO.h"
#include "domain/query/collectionplans/CollectionPlansQuery.h"
#include "domain/vo/collectionplans/CollectionPlansVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

// 定义前缀
#ifndef CPC_PRFIX
#define CPC_PRFIX(_app_) "/collection-man/collectionplans" _app_
#endif

/**
 * 回款计划操作接口实现
 */
class CollectionPlansController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CollectionPlansController);
public: // 定义接口
	// 获取回款计划列表
	ENDPOINT_INFO(queryCollectionPlansList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("collectionplans.get-collectionplans.get"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	    API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CollectionPlansPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 回款日期
		API_DEF_ADD_QUERY_PARAMS(String, "backdate", ZH_WORDS_GETTER("collectionplans.field.backdate1"), "2023-11-11", false);
		// 合同订单名称
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("collectionplans.field.contract"), "Kim Lewis", false);
		// 创建的时间
		API_DEF_ADD_QUERY_PARAMS(String, "createdate", ZH_WORDS_GETTER("collectionplans.field.createdate1"), "2023-11-11", false);
		// 查询是否付款
		API_DEF_ADD_QUERY_PARAMS(String, "ifpay", ZH_WORDS_GETTER("collectionplans.field.ifpay"), "YES", false);

	}
	ENDPOINT(API_M_GET, CPC_PRFIX("/get-collectionplans"), queryCollectionPlansList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, CollectionPlansQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCollection(userQuery, authObject->getPayload()));
	}


	// 添加回款计划
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addCollectionPlans) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("collectionplans.add-collection.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, CPC_PRFIX("/add-collection"), addCollectionPlans, BODY_DTO(AddCollectionPlanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCollectionPlans(dto, authObject->getPayload()));

	}


private: // 定义接口执行函数
	// 获取回款计划列表
	CollectionPlansPageJsonVO::Wrapper execQueryCollection(const CollectionPlansQuery::Wrapper& query, const PayloadDTO& payload);
	//
	Uint64JsonVO::Wrapper execAddCollectionPlans(const AddCollectionPlanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COLLECTIONPLANSCONTROLLER_H_