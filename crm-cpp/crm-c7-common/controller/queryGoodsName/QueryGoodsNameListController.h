#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/11/02 16:56:07

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
#ifndef _GETGOODSNAMELISTCONTROLLER_H_
#define _GETGOODSNAMELISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/vo/PullListJsonVO.h"
#include "../../domain/query/PullListQuery.h"
#include "domain/vo/goodsCategory/GoodsCategoryJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryGoodsNameListController : public oatpp::web::server::api::ApiController
{
    // 定义控制器访问入口
    API_ACCESS_DECLARE(QueryGoodsNameListController);
public: // 定义接口
	ENDPOINT_INFO(queryGoodsNameList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goods-manage.goods-category.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(GoodsCategoryJsonVO);
	}
	ENDPOINT(API_M_GET, COMMON(/goods-category-name-list), queryGoodsNameList, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryGoodsNameList(authObject->getPayload()));
	}
private: // 定义接口执行函数
	GoodsCategoryJsonVO::Wrapper execQueryGoodsNameList(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETGOODSNAMELISTCONTROLLER_H_