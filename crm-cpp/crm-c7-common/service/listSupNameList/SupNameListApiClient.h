#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/28 18:55:06

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
#ifndef _SUPNAMELISTAPICLIENT_H_
#define _SUPNAMELISTAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

class SupNameListApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(SupNameListApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 多条件查询
	API_CALL(API_M_GET, "supplier-manage/supplier/query-supplier-name", querySupNameList, API_HANDLER_AUTN_HEADER, QUERY(String, name));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_SUPNAMELISTAPICLIENT_H_