#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 20:23:31

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
#ifndef _SALEOPPOTUNITYAPICLIENT_H_
#define _SALEOPPOTUNITYAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 销售管理公用接口声明式服务ApiClient
 * 负责人: Andrew
 */
class SaleManageApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(SaleManageApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 获取销售机会名称列表
	API_CALL(API_M_GET, "sales-opportunities/sales-oppo-name-list", querySaleOpportunity, API_HANDLER_AUTN_HEADER, QUERY(UInt32, customer_id), QUERY(String, name));
	// 获取销售合同名称列表
	API_CALL(API_M_GET, "sales-contract/sales-cont-list", querySaleContract, API_HANDLER_AUTN_HEADER, QUERY(UInt32, customer_id), QUERY(String, title));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_SALEOPPOTUNITYAPICLIENT_H_