#pragma once
/*
 @Author: linglan
 @Date: 2023/10/24 17:39:52

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
#ifndef _PAYMENTPLANDAO_H_
#define _PAYMENTPLANDAO_H_

#include "BaseDAO.h"
#include "domain/query/payment_plan/PaymentPlanQuery.h"
#include "domain/do/payment_plan/PaymentPlanDO.h"

//查询付款计划信息(分页) 负责人：灵岚
class PaymentPlanDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PaymentPlanQuery::Wrapper& query);
	// 分页查询数据
	list<PaymentPlanDO> selectWithPage(const PaymentPlanQuery::Wrapper& query);
};

#endif // !_PAYMENTPLANDAO_H_