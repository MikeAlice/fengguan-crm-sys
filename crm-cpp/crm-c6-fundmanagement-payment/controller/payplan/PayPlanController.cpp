/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/29 14:27:57

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
#include "stdafx.h"
#include "PayPlanController.h"
#include "../../service/payplan/PayPlanService.h"

Uint64JsonVO::Wrapper PayPlanController::execPayPlanPost(const PayPlanDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->contract_id || !dto->contract_name || !dto->suplier_id || !dto->suplier_name || !dto->datee || !dto->money)
	{
		jvo->fail(1);
	}
	else
	{
		PayPlanService s;
		if (s.addPayPlan(dto))
			jvo->fail(1);
		jvo->success(10000);
	}
	return jvo;
}
