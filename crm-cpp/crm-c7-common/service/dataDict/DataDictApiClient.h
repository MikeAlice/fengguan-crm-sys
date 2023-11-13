#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/06 17:51:00

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
#ifndef _DATADICTAPICLIENT_H_
#define _DATADICTAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

class DataDictApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(DataDictApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 获取指定字典分类对应字典列表
	API_CALL(API_M_GET, "data-dictionary/dictclassify/get-dictclassifylist", queryDictType, API_HANDLER_AUTN_HEADER);
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_DATADICTAPICLIENT_H_