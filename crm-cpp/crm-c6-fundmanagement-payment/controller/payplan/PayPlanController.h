#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/29 14:27:28

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
#ifndef _PAYPLANCONTROLLER_H_
#define _PAYPLANCONTROLLER_H_

#include "stdafx.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/payplan/PayPlanDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PayPlanController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PayPlanController);
public: // 定义接口
	ENDPOINT_INFO(payPlanPost)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payplan.con.post"));
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	API_HANDLER_ENDPOINT(API_M_POST, "/payment/pay-plan/post", payPlanPost, BODY_DTO(PayPlanDTO::Wrapper, dto), execPayPlanPost(dto))
private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execPayPlanPost(const PayPlanDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAYPLANCONTROLLER_H_