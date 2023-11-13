#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hf
 @Date: 2022/10/25 0:27:04

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
#ifndef _UPDATEPAYPLAN_CONTROLLER_
#define _UPDATEPAYPLAN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/collectionplan/updatePayPlanDTO.h"
#include "domain/dto/collectionplan/updateConfirmPlanDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// 定义路径前缀
#ifndef UPPC_PRFIX
#define UPPC_PRFIX(_app_) "/collection-man" _app_
#endif

/**
 * 修改回款计划操作接口实现
 */
class updatePayPlanController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(updatePayPlanController);
	// 3 定义接口
public:
	
	// 修改回款计划
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("collectionplan.update-pay-plan.summary"), updatePayPlan, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, UPPC_PRFIX("/update-pay-plan"), updatePayPlan, BODY_DTO(updatePayPlanDTO::Wrapper, dto), execUpdatePayPlan(dto, authObject->getPayload()));

	// 确认回款计划
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("collectionplan.update-confirm-plan.summary"), updateConfirmPlan, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, UPPC_PRFIX("/update-confirm-plan"), updateConfirmPlan, BODY_DTO(updateConfirmPlanDTO::Wrapper, dto), execUpdateConfirmPlan(dto, authObject->getPayload()));
private:
	Uint64JsonVO::Wrapper execUpdatePayPlan(const updatePayPlanDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execUpdateConfirmPlan(const updateConfirmPlanDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _UPDATEPAYPLANCONTROLLER_CONTROLLER_