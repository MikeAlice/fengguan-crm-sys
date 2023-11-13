#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/11/01 15:50:19

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
#ifndef _WAREHOUSEAPICLIENT_H_
#define _WAREHOUSEAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class WarehouseApiClient : public oatpp::web::client::ApiClient
{
	// 初始化定义
	API_CLIENT_INIT(WarehouseApiClient)
	// 声明式调用服务接口
	API_CALL(API_M_GET, "j3-controller-warehouse/getStoreSelect", warehouse, API_HANDLER_AUTN_HEADER, QUERY(String, keyWord))
};

#include OATPP_CODEGEN_END(ApiClient)

#endif // !_WAREHOUSEAPICLIENT_H_