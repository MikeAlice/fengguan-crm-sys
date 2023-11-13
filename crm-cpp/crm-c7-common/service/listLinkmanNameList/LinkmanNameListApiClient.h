#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/29 13:55:06

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
#ifndef _LINKMAN_NAME_LIST_APICLIENT_
#define _LINKMAN_NAME_LIST_APICLIENT_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

class LinkmanNameListApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(LinkmanNameListApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 多条件查询
	API_CALL(API_M_GET, "supplier-manage/supplier-linkman/query-name-pull-list", queryLinkmanNameList, API_HANDLER_AUTN_HEADER, QUERY(String, keywords));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_LINKMAN_NAME_LIST_APICLIENT_
