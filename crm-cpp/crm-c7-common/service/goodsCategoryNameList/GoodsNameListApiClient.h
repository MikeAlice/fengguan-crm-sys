#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ��
 @Date: 2023/11/03 9:48:04

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
#ifndef _GOODSNAMELISTAPICLIENT_H_
#define _GOODSNAMELISTAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"
#include "../../domain/query/PullListQuery.h"

class GoodsNameListApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

    // ��ʼ������
    API_CLIENT_INIT(GoodsNameListApiClient);

    // ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
    API_CALL(API_M_GET, "goods/category/list-goods-category-name-tree", queryGoodsNameList, API_HANDLER_AUTN_HEADER);

#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_GOODSNAMELISTAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

