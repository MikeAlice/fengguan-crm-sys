#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/02 18:53:14

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
#ifndef _CLIENTMANAGEAPICLIENT_H_
#define _CLIENTMANAGEAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 客户管理模块声明式服务ApiClient
 * 负责人: Andrew & tapioca
 */
class ClientManageApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(ClientManageApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 获取客户名称列表
	// 负责人: Andrew
	API_CALL(API_M_GET, "customer-mycustomer/get-customername", queryClientName, API_HANDLER_AUTN_HEADER, QUERY(String, name));
	// 获取联系人名称列表
	// 负责人: tapioca
	API_CALL(API_M_GET, "customer-contact/query-contact-name", queryContactName, API_HANDLER_AUTN_HEADER, QUERY(UInt32, customer_id), QUERY(String, name));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_CLIENTMANAGEAPICLIENT_H_